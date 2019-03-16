#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ctrl->initRepo();
    this->populateTable();

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addRepo()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRepo()));
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(updateRepo()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startWatchlist()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextMovie()));
    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playTrailer()));
    connect(ui->addWLButton, SIGNAL(clicked()), this, SLOT(addWatchlist()));
    connect(ui->deleteWLButton, SIGNAL(clicked()), this, SLOT(deleteWatchlist()));
    connect(ui->filterButton, SIGNAL(clicked()), this, SLOT(filterRepo()));
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_currentTextChanged(QString)));
    connect(ui->htmlButton, SIGNAL(clicked()), this, SLOT(htmlOpen()));
    connect(ui->csvButton, SIGNAL(clicked()), this, SLOT(csvOpen()));
    connect(ui->undoButton, SIGNAL(clicked()), this, SLOT(undoRepo()));
    connect(ui->redoButton, SIGNAL(clicked()), this, SLOT(redoRepo()));
    connect(ui->showButton, SIGNAL(clicked()), this, SLOT(showTable()));
    connect(ui->undoWButton, SIGNAL(clicked()), this, SLOT(undoWL()));
    connect(ui->redoWButton, SIGNAL(clicked()), this, SLOT(redoWL()));


}


void MainWindow::showTable()
{

    MoviesTableModel* moviesModel = new MoviesTableModel(*new Repo((*new vector<Movie>(this->ctrl->getWatchList()->getMovs()))));
    MoviesView* view = new MoviesView{};
    view->setModel(moviesModel);
    view->show();

}

void MainWindow::undoRepo()
{
    try
    {
        this->ctrl->undo();
        this->populateTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::undoWL()
{
    try
    {
        this->ctrl->undoWL();
        this->populateWLTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::redoRepo()
{
    try
    {
        this->ctrl->redo();
        this->populateTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::redoWL()
{
    try
    {
        this->ctrl->redoWL();
        this->populateWLTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::htmlOpen()
{
    this->g->writeToFile();
    this->ctrl->openWatchList();
}

void MainWindow::csvOpen()
{
    this->f->writeToFile();
    this->ctrl->openWatchList();

}


void MainWindow::populateTable()
{
    int index = 0;
    ui->tableRepo->setRowCount(this->ctrl->getRepo().getMovies().size());

    ui->tableRepo->setColumnCount(6);
    ui->tableRepo->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));
    ui->tableRepo->setHorizontalHeaderItem(1, new QTableWidgetItem("Genre"));
    ui->tableRepo->setHorizontalHeaderItem(2, new QTableWidgetItem("Year of release"));
    ui->tableRepo->setHorizontalHeaderItem(3, new QTableWidgetItem("Number of likes"));
    ui->tableRepo->setHorizontalHeaderItem(4, new QTableWidgetItem("Trailer"));
    ui->tableRepo->setHorizontalHeaderItem(5, new QTableWidgetItem("Duration"));

    for(Movie& m : this->ctrl->getRepo().getMovies())
    {
        ui->tableRepo->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(m.getTitle())));
        ui->tableRepo->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(m.getGenre())));
        ui->tableRepo->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(to_string(m.getYearOfRelease()))));
        ui->tableRepo->setItem(index, 3, new QTableWidgetItem(QString::fromStdString(to_string(m.getnrLikes()))));
        ui->tableRepo->setItem(index, 4, new QTableWidgetItem(QString::fromStdString(m.getTrailer())));
        ui->tableRepo->setItem(index, 5, new QTableWidgetItem(QString::fromStdString(to_string(m.getDuration()))));
        index++;
     }

}

void MainWindow::populateTableShort()
{
    int index = 0;
    ui->tableRepo->setRowCount(this->ctrl->getRepo().getMovies().size());

    ui->tableRepo->setColumnCount(1);
    ui->tableRepo->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));

    for(Movie& m : this->ctrl->getRepo().getMovies())
    {
        ui->tableRepo->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(m.getTitle())));
        index++;
     }
}

void MainWindow::addRepo()
{
    QString titleLabel = ui->titleLineEdit->text();
    QString genreLabel = ui->genreLineEdit->text();
    QString yearOfReleaseLabel = ui->yearofreleaseLineEdit->text();
    QString nrLikesLabel = ui->nrlikesLineEdit->text();
    QString trailerLabel = ui->trailerLineEdit->text();
    QString durationLabel = ui->durationLineEdit->text();

    string tit = titleLabel.toStdString();
    string gen = genreLabel.toStdString();
    int year = yearOfReleaseLabel.toInt();
    int nrlikes = nrLikesLabel.toInt();
    string tra = trailerLabel.toStdString();
    int dur = durationLabel.toInt();

    try
    {
        this->ctrl->addMovieToRepo(tit, gen, year, nrlikes, tra, dur);
        this->populateTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::deleteRepo()
{
    QString titleLabel = ui->titleLineEdit->text();
    QString yearOfReleaseLabel = ui->yearofreleaseLineEdit->text();

    string tit = titleLabel.toStdString();
    int year = yearOfReleaseLabel.toInt();

    try
    {
        this->ctrl->delMovieRepo(tit, year);
        this->populateTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::updateRepo()
{

    QString titleLabel = ui->titleLineEdit->text();
    QString genreLabel = ui->genreLineEdit->text();
    QString yearOfReleaseLabel = ui->yearofreleaseLineEdit->text();
    QString nrLikesLabel = ui->nrlikesLineEdit->text();
    QString trailerLabel = ui->trailerLineEdit->text();
    QString durationLabel = ui->durationLineEdit->text();

    string tit = titleLabel.toStdString();
    string gen = genreLabel.toStdString();
    int year = yearOfReleaseLabel.toInt();
    int nrlikes = nrLikesLabel.toInt();
    string tra = trailerLabel.toStdString();
    int dur = durationLabel.toInt();

    Movie movie{tit, gen, year, nrlikes, tra, dur};
    try
    {
        this->ctrl->updateMovieRepo(tit, year, movie);
        this->populateTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

void MainWindow::filterRepo()
{
    QString genreLabel = ui->genreLineEdit->text();
    string gen = genreLabel.toStdString();

    this->ctrl->filter(gen);
    this->populateTable();
    this->populateWLTable();
}

void MainWindow::populateList()
{

    Movie m = this->ctrl->getRepo().getCurrentMovie();

    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(m.getTitle()));
    QListWidgetItem* item2 = new QListWidgetItem(QString::fromStdString(m.getGenre()));
    QListWidgetItem* item3 = new QListWidgetItem(QString::fromStdString(to_string(m.getYearOfRelease())));
    QListWidgetItem* item4 = new QListWidgetItem(QString::fromStdString(to_string(m.getnrLikes())));
    QListWidgetItem* item5 = new QListWidgetItem(QString::fromStdString(m.getTrailer()));
    QListWidgetItem* item6 = new QListWidgetItem(QString::fromStdString(to_string(m.getDuration())));
    ui->watchlist->insertItem(0, item);
    ui->watchlist->insertItem(1, item2);
    ui->watchlist->insertItem(2, item3);
    ui->watchlist->insertItem(3, item4);
    ui->watchlist->insertItem(4, item5);
    ui->watchlist->insertItem(5, item6);
}

void MainWindow::populateWLTable()
{
    int index = 0;
    ui->watchlistALL->setRowCount(this->ctrl->getWatchList()->getMovs().size());

    for(Movie& m : this->ctrl->getWatchList()->getMovs())
    {
        ui->watchlistALL->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(m.getTitle())));
        ui->watchlistALL->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(m.getGenre())));
        ui->watchlistALL->setItem(index, 2, new QTableWidgetItem(QString::fromStdString(to_string(m.getYearOfRelease()))));
        ui->watchlistALL->setItem(index, 3, new QTableWidgetItem(QString::fromStdString(to_string(m.getnrLikes()))));
        ui->watchlistALL->setItem(index, 4, new QTableWidgetItem(QString::fromStdString(m.getTrailer())));
        ui->watchlistALL->setItem(index, 5, new QTableWidgetItem(QString::fromStdString(to_string(m.getDuration()))));
        index++;
     }
}


void MainWindow::startWatchlist()
{
    this->ctrl->startWatchList();
    this->populateList();
}

void MainWindow::nextMovie()
{
    this->ctrl->nextMovieWatchList();
    ui->watchlist->clear();
    this->populateList();
}

void MainWindow::playTrailer()
{
    this->ctrl->getRepo().getCurrentMovie().playTrailer();
}

void MainWindow::addWatchlist()
{
    Movie m = this->ctrl->getRepo().getCurrentMovie();
    this->ctrl->addMovieToWatchList(m);

    this->populateWLTable();
}

void MainWindow::deleteWatchlist()
{
    QString titleLabel = ui->titleLineEdit->text();
    QString yearOfReleaseLabel = ui->yearofreleaseLineEdit->text();

    string tit = titleLabel.toStdString();
    int year = yearOfReleaseLabel.toInt();

    try
    {
        this->ctrl->delMovieFromWatchList(tit, year);
        this->populateWLTable();
    }
    catch(Exception& e)
    {
         QMessageBox::critical( this, "Eroare", "Salvarea nu s-a putut executa: " + QString::fromStdString(e.what()) );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentIndex() == 1)
    {
        ui->tableRepo->clear();
        this->populateTableShort();
    }
    else
    {
        ui->tableRepo->clear();
        this->populateTable();
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}
