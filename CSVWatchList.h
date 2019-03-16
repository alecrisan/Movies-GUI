#ifndef CSVWATCHLIST_H
#define CSVWATCHLIST_H


#include "FileWatchList.h"

class CSVWatchList : public FileWatchList
{
public:
    /*
     Constructor with parameters for a CSVWatchList
     */
    CSVWatchList(const string& filename) : FileWatchList{ filename } {}

    /*
     Writes the watchlist to file.
     Throws an Exception if it can't write
     */
    void writeToFile() override;

    /*
     Displays the watchlist using a text editor
     */
    void displayWatchList() const override;
};

#endif // CSVWATCHLIST_H
