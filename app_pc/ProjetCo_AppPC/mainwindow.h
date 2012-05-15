#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDrag>
#include <QDropEvent>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <phonon/phonon>
#include <QFormLayout>
#include <QSound>
#include <QIcon>

#include <iostream>

#include "aboutwindow.h"
#include "modifquestionwindow.h"
#include "categoriebdd.h"

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
        QStandardItemModel * model;
        QStandardItemModel * model2;
        QIcon greenIcon;
        QIcon yellowIcon;
        QIcon redIcon;
        QAction * addQuestion;
        QAction * modifQuestion;
        QAction * delQuestion;
        ListeQuestion * maListeQuestions;

        void peuplerListeQuestions();
        void peuplerListeQuestionsXML();
        void peuplerListeReponses();
        void createAction();

    private slots:
        void on_actionQuitter_triggered();
        void on_actionExporter_XML_triggered();
        void on_actionImporter_XML_triggered();
        void on_actionApropos();
        void on_clickTreeViewQuestions(const QModelIndex &index);
        void treeQuestionsContextMenu(const QPoint&);
        void newQuestion();
        void modifierQuestion();
        void supprimerQuestion();
};

#endif // MAINWINDOW_H
