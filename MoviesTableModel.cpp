#include "MoviesTableModel.h"
#include <QFont>
#include <QPushButton>

MoviesTableModel::MoviesTableModel(Repo& repo, QObject* parent) : QAbstractTableModel{ parent }, r{ repo } {}

int MoviesTableModel::rowCount(const QModelIndex& parent) const
{
    return (this->r.getMovies().size());
}

int MoviesTableModel::columnCount(const QModelIndex& parent) const
{
    return 6;
}

QVariant MoviesTableModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    vector<Movie> movies = this->r.getMovies();

    if (row == movies.size())
    {
        return QVariant();
    }

    Movie m = movies[row];

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (col)
        {
        case 0:
            return QString::fromStdString(m.getTitle());
        case 1:
            return QString::fromStdString(m.getGenre());
        case 2:
            return QString::fromStdString(to_string(m.getYearOfRelease()));
        case 3:
            return QString::fromStdString(to_string(m.getnrLikes()));
        case 4:
            return QString::fromStdString(m.getTrailer());
        case 5:
            return QString::fromStdString(to_string(m.getDuration()));
        default:
            break;
        }
    }

    if (role == Qt::FontRole)
    {
        QFont font("Helvetica", 14, 10, true);
        return font;
    }

    return QVariant{};
}

bool MoviesTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    // set the new data to the gene
    int movieIndex = index.row();

    // get the genes
    std::vector<Movie> movies = this->r.getMovies();

    // Allow adding in the table
    //if the index is >= number of genes => a new gene is added
    if (movieIndex == movies.size())
    {
        this->beginInsertRows(QModelIndex{}, movieIndex, movieIndex);

        switch (index.column())
        {
        case 0:
            this->r.addMovie(Movie{value.toString().toStdString(), "", 0, 0, "", 0});
            break;
//        case 1:
//            this->r.addMovie(Movie{" ", value.toString().toStdString(), "", "", "", ""});
//            break;
//        case 2:
//            this->r.addMovie(Movie{" ", " ", value.toString().toStdString(), "", "", ""});
//            break;
        }

        this->endInsertRows();
        return true;
    }

    Movie& currentmov = movies[movieIndex];
    switch (index.column())
    {
    case 0:
        currentmov.setTitle(value.toString().toStdString());
        break;
//	case 1:
//		currentGene.setOrganismName(value.toString().toStdString());
//		break;
//	case 2:
//		currentGene.setFunction(value.toString().toStdString());
    }
    this->r.updateMovie(movieIndex, currentmov);

    // emit the dataChanged signal
    emit dataChanged(index, index);

    return true;
}

QVariant MoviesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString{ "Title" };
            case 1:
                return QString{ "Genre" };
            case 2:
                return QString{ "Year of release" };
            case 3:
                return QString{ "Number of likes" };
            case 4:
                return QString{ "Trailer" };
            case 5:
                return QString{ "Duration" };
            default:
                break;
            }
        }
    }

    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags MoviesTableModel::flags(const QModelIndex & index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

MoviesTableModel::~MoviesTableModel() {}
