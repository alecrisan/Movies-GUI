#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "AdminDatabase.h"
#include "MovieValidator.h"
#include "FileWatchList.h"
#include "UndoAction.h"
#include "Exception.h"
#include "UndoAdd.h"
#include "UndoDelete.h"
#include "UndoUpdate.h"
#include "UndoAddWL.h"
#include "UndoDeleteWL.h"

class Controller
{
private:
    Repo repo;
    FileWatchList* watchlist;
    MovieValidator validator;
    vector<UndoAction*> actionsUndo;
    vector<UndoAction*> actionsRedo;
    vector<UndoAction*> actionsWLUndo;
    vector<UndoAction*> actionsWLRedo;

public:
    Controller(){}
    /*
     Constructor for a controller
     Input: r - Repo
            w - pointer to a filewatchlist
            val - MovieValidator
     */
    Controller(const Repo& r, FileWatchList* w, MovieValidator val) : repo{r}, watchlist{w}, validator{val}{}

    /*
     Gets the repo from the controller
     */
    Repo getRepo() const { return repo; }


    /*
     Gets the watchlist from the controller
     */
    FileWatchList* getWatchList() {return watchlist;}


    /*
     Adds a movie to the user's watchlist
     Input: m - a movie
     Output: the movie is added
     */
    int addMovieToWatchList(const Movie& m);


    /*
     Deletes a movie from the user's watchlist
     Input: title - string
            yearOfRelease - integer
     Output: 1 if it was deleted successfully, 0 otherwise
     */
    int delMovieFromWatchList(const string& title, int yearOfRelease);


    /*
     Adds a movie with the given data to the repository
     Input: title - string
            genre - string
            yearOfRelease - integer
            nrLikes - integer
            trailer - string
     Output: Throws an Exception if the movie already exists
                    a MovieException is the movie is not valid
     */
    void addMovieToRepo(const string& title, const string& genre, int yearOfRelease, int nrLikes, const string& trailer, int duration);


    /*
     Deletes a movie from the repository
     Input: title - string
            yearOfRelease - integer
     Output: Throws an Exception if the movie doesn't exist
     */
    void delMovieRepo(const string& title, int yearOfRelease);


    /*
     Updates a movie from the repository
     Input: title - string
            yearOfRelease - integer
            newM - the new movie
     Output: Throws an Exception if the movie doesn't exist
                    a MovieException if the new movie is not valid
     */
    void updateMovieRepo(const string& title, int yearOfRelease, Movie& newM);

    /*
     Filters the movies by a given genre
     Input: genre - string
     Output: None
     */
    void filter(const string& genre);


    /*
     Filters the movies by a given string
     Input: s - string
     Output: None
     */
    void filterByString(const string& s)
    {
        this->repo.filterEverything(s);
    }

    /*
     Starts viewing the movies one by one
     */
    void startWatchList();

    /*
     Moves to the next movie in the repo
     */
    void nextMovieWatchList();

    /*
     Opens the watchlist in a text editor
     */
    void openWatchList();

    /*
     Initializes the repository
     */
    void initRepo();

    /*
     Performs an undo on the last operation made on the repository
     */
    void undo();

    /*
     Performs an undo on the last operation made on the watchlist
     */
    void undoWL();

    /*
     Performs a redo on the last operation made on the repository
     */
    void redo();

    /*
     Performs a redo on the last operation made on the watchlist
     */
    void redoWL();

    /*
     Destructor for a controller
     */
    ~Controller()
    {
        for(auto action: this->actionsUndo)
            delete action;
        for(auto action: this->actionsRedo)
            delete action;
        for(auto action: this->actionsWLUndo)
            delete action;
        for(auto action: this->actionsWLRedo)
            delete action;
    }
};
#endif // CONTROLLER_H
