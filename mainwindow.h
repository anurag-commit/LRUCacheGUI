#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lrucache.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LRUCache* cache;

private slots:
    void onPutClicked();
    void onGetClicked();
    void updateCacheTable();
    void updateRemovedLabel(const QString& removedKey);
};

#endif // MAINWINDOW_H
