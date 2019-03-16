#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Controller.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include <QTableWidget>
#include "MoviesView.h"
#include <QMessageBox>
#include "Exception.h"
#include "MoviesTableModel.h"

namespace Ui {
class MainWindow;
class MoviesView;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Repo r{};
    FileWatchList* f = new CSVWatchList{"testWatchList.csv"};
    FileWatchList* g = new HTMLWatchList{"WatchList.html"};
    FileWatchList* e;
    MovieValidator val{};
    Controller* ctrl = new Controller{r, g, val};


private slots:
    void populateTable();
    void populateTableShort();
    void addRepo();
    void deleteRepo();
    void updateRepo();
    void filterRepo();
    void undoRepo();
    void redoRepo();

    void showTable();

    void populateList();
    void populateWLTable();
    void startWatchlist();
    void nextMovie();
    void playTrailer();
    void addWatchlist();
    void deleteWatchlist();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_comboBox_activated(const QString &arg1);
    void htmlOpen();
    void csvOpen();
    void undoWL();
    void redoWL();

};

#endif // MAINWINDOW_H
