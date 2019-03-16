#ifndef UNDOADD_H
#define UNDOADD_H

#include "UndoAction.h"
#include "Movie.h"
#include "AdminDatabase.h"

class UndoAdd : public UndoAction
{
private:
    Movie addedMovie;
    Repo &repo;
public:
    /*
    Constructor with parameters
    */
    UndoAdd(Movie m, Repo &r): addedMovie(m), repo(r) {}

    /*
    Function that executes the undo
    */
    void executeUndo()
    {
        int poz = this->repo.findPoz(this->addedMovie.getTitle(), this->addedMovie.getYearOfRelease());
        this->repo.delMovie(poz);
    }

    /*
    Default destructor
    */
    ~UndoAdd() {}
};

#endif // UNDOADD_H
