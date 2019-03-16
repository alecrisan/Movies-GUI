#ifndef UNDOUPDATE_H
#define UNDOUPDATE_H

#include "UndoAction.h"
#include "Movie.h"
#include "AdminDatabase.h"

class UndoUpdate : public UndoAction
{
private:
    Movie updatedMovie;
    Repo &repo;

public:
    /*
    Constructor with parameters
    */
    UndoUpdate(Movie m, Repo& r): updatedMovie(m), repo(r) {}

    /*
    Function that executes the undo
    */
    void executeUndo()
    {
        int poz = this->repo.findPoz(this->updatedMovie.getTitle(), this->updatedMovie.getYearOfRelease());
        Movie m{this->updatedMovie.getTitle(),this->updatedMovie.getGenre(), this->updatedMovie.getYearOfRelease(),
               this->updatedMovie.getnrLikes(), this->updatedMovie.getTrailer(), this->updatedMovie.getDuration()};
        this->repo.updateMovie(poz, m);
    }

    /*
    Default destructor
    */
    ~UndoUpdate() {}
};

#endif // UNDOUPDATE_H
