#include "MoviesView.h"


MoviesView::MoviesView(MoviesTableModel* m, QWidget *parent) : QWidget(parent), model{ m } {
    ui.setupUi(this);
    ui.tableView->setModel(this->model);

}

void MoviesView::setModel(MoviesTableModel* model) {
    ui.setupUi(this);
    ui.tableView->setModel(model);

}
