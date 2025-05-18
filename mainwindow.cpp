#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    cache(new LRUCache(10))  // Cache with capacity 10
{
    ui->setupUi(this);

    connect(ui->buttonPut, &QPushButton::clicked, this, &MainWindow::onPutClicked);
    connect(ui->buttonGet, &QPushButton::clicked, this, &MainWindow::onGetClicked);

    updateRemovedLabel("None");
    updateCacheTable();
}

MainWindow::~MainWindow()
{
    delete cache;
    delete ui;
}

void MainWindow::onPutClicked() {
    bool ok;
    int key = ui->lineEditKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer key.");
        return;
    }

    QString value = ui->lineEditValue->text();
    if (value.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a value.");
        return;
    }

    QString removedKey = cache->put(key, value);
    if (!removedKey.isEmpty()) {
        updateRemovedLabel(removedKey);
    } else {
        updateRemovedLabel("None");
    }
    updateCacheTable();
}

void MainWindow::onGetClicked() {
    bool ok;
    int key = ui->lineEditKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer key.");
        return;
    }

    QString value = cache->get(key);
    if (value == "NOT FOUND") {
        QMessageBox::information(this, "Cache Miss", "Key not found in cache.");
        ui->lineEditValue->clear();
    } else {
        ui->lineEditValue->setText(value);
    }
    updateCacheTable();
}

void MainWindow::updateCacheTable() {
    auto items = cache->getAll();
    ui->tableCache->clear();
    ui->tableCache->setColumnCount(2);
    ui->tableCache->setHorizontalHeaderLabels({"Key", "Value"});
    ui->tableCache->setRowCount(static_cast<int>(items.size()));

    int row = 0;
    for (auto& kv : items) {
        QTableWidgetItem* keyItem = new QTableWidgetItem(QString::number(kv.first));
        QTableWidgetItem* valueItem = new QTableWidgetItem(kv.second);
        ui->tableCache->setItem(row, 0, keyItem);
        ui->tableCache->setItem(row, 1, valueItem);
        row++;
    }
    ui->tableCache->resizeColumnsToContents();
}

void MainWindow::updateRemovedLabel(const QString& removedKey) {
    ui->labelRemoved->setText("Last removed key: " + removedKey);
}
