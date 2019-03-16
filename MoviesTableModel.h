#ifndef MOVIESTABLEMODEL_H
#define MOVIESTABLEMODEL_H

#include<QAbstractTableModel>
#include "AdminDatabase.h"

class MoviesTableModel : public QAbstractTableModel
{
private:
    Repo& r;
public:
    /*
     Constructor with parameters
     */
    MoviesTableModel(Repo& repo, QObject* parent = NULL);

    /*
    Gets the row count of the table
    */
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

    /*
    Gets the column count of the table
    */
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    /*
    Adds data in the table
    */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex & index, const QVariant & value, int role) override;
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    /*
    Adds the header data
    */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    /*
    Default destructor
    */
    ~MoviesTableModel();
};

#endif // MOVIESTABLEMODEL_H
