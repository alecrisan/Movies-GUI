#ifndef UNDODELETE_H
#define UNDODELETE_H


#include "UndoAction.h"
#include "Movie.h"
#include "AdminDatabase.h"

class UndoDelete : public UndoAction
{
private:
    Movie deletedMovie;
    Repo &repo;
public:
    /*
    Constructor with parameters
    */
    UndoDelete(Movie m, Repo &r): deletedMovie(m), repo(r) {}

    /*
    Function that executes the undo
    */
    void executeUndo()
    {
        this->repo.addMovie(this->deletedMovie);
    }

    /*
    Default destructor
    */
    ~UndoDelete() {}
};

#endif // UNDODELETE_H
