#ifndef HTMLWATCHLIST_H
#define HTMLWATCHLIST_H


#include <stdio.h>
#include "FileWatchList.h"

class HTMLWatchList : public FileWatchList
{
public:
    /*
     Constructor with parameters for a HTMLWatchList
     */
    HTMLWatchList(const string& filename) : FileWatchList{ filename } {}

    /*
     Writes the watchlist to file.
     Throws an Exception if it can't write
     */
    void writeToFile() override;

    /*
     Displays the watchlist using a browser
     */
    void displayWatchList() const override;
};

#endif // HTMLWATCHLIST_H
