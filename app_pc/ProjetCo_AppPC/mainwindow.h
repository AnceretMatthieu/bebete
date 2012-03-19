#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QCloseEvent>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);
    
private:
    Ui::MainWindow *ui;

private slots:
    void on_actionQuitter_triggered();
    void on_actionExporter_XML_triggered();
    void on_actionImporter_XML_triggered();
};

#endif // MAINWINDOW_H
