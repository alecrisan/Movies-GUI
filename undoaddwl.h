#ifndef UNDOADDWL_H
#define UNDOADDWL_H

#include "UndoAction.h"
#include "Movie.h"
#include "FileWatchList.h"

class UndoAddWL : public UndoAction
{
private:
    Movie addedMovie;
    FileWatchList* f;
public:
    /*
    Constructor with parameters
    */
    UndoAddWL(Movie m, FileWatchList* fw): addedMovie(m), f(fw) {}

    /*
    Function that executes the undo
    */
    void executeUndo()
    {

        this->f->del(this->addedMovie.getTitle(), this->addedMovie.getYearOfRelease());
    }

    /*
    Default destructor
    */
    ~UndoAddWL() {}
};

#endif // UNDOADDWL_H
