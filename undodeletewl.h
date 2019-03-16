#ifndef UNDODELETEWL_H
#define UNDODELETEWL_H

#include "UndoAction.h"
#include "Movie.h"
#include "FileWatchList.h"

class UndoDeleteWL : public UndoAction
{
private:
    Movie deletedMovie;
    FileWatchList* f;
public:
    /*
    Constructor with parameters
    */
    UndoDeleteWL(Movie m, FileWatchList* fw): deletedMovie(m), f(fw) {}

    /*
    Function that executes the undo
    */
    void executeUndo()
    {
        this->f->add(deletedMovie);
    }

    /*
    Default destructor
    */
    ~UndoDeleteWL() {}
};

#endif // UNDODELETEWL_H
