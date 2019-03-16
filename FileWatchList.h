#ifndef FILEWATCHLIST_H
#define FILEWATCHLIST_H

#include "WatchList.h"

class FileWatchList : public WatchList
{
protected:
    string filename;

public:
    /*
     Constructor with parameters for a FileWatchList
     */
    FileWatchList(const string& filename)
    {
        this->filename = filename;
    }

    /*
     Virtual destructor for a FileWatchList
     */
    virtual ~FileWatchList() {}

    /*
     Virtual function that writes to a file
     */
    virtual void writeToFile() = 0;

    /*
     Virtual function that displays the watchlist
     */
    virtual void displayWatchList() const = 0;
};

#endif // FILEWATCHLIST_H
