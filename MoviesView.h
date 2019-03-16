#ifndef MOVIESVIEW_H
#define MOVIESVIEW_H

#include <QWidget>
#include "ui_secondwindow.h"
#include "MoviesTableModel.h"


class MoviesView : public QWidget {
    Q_OBJECT

public:
    /*
    Constructor with parameters
    */
    MoviesView(MoviesTableModel* model, QWidget *parent = Q_NULLPTR);

    /*
    Default constructor
    */
    MoviesView() = default;

    /*
    Sets the given table model
    */
    void setModel(MoviesTableModel* model);

    /*
    Default destructor
    */
    ~MoviesView() = default;

private:
    Ui::Form ui;
    MoviesTableModel* model;


};

#endif // MOVIESVIEW_H
