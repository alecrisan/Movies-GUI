#ifndef WATCHLIST_H
#define WATCHLIST_H


#include "Movie.h"
#include <vector>

class WatchList
{

protected:
    vector<Movie> movs;
    int current;

public:

    /*
     Default constructor for a WatchList
     */
    WatchList();

    /*
     Adds a song to the user's watchlist
     Input: m - a movie
     Output: the movie is added
     */
    void add(const Movie& m);


    /*
     Deletes a song from the user's watchlist
     Input: title - string
            yearOfRelease - integer
     Output: the movie is deleted
     */
    void del(const string& title, int yearOfRelease);


    /*
     Finds the position of a movie in the watchlist
     Input: title - string
            yearOfRelease - integer
     Output: the position, an integer, or -1 if the movie wasn't found
     */
    int findPoz(const string& title, int yearOfRelease);


    /*
     Finds a movie by a given title and year of release
     Input: title - string
            yearOfRelease - integer
     Output: a Movie
     */
    Movie findByTitleAndYear(const string& title, int yearOfRelease)
    {
        vector<Movie> v = this->movs;

        Movie found {title, " ", yearOfRelease, 0, " ", 0};

        for (auto m : this->movs)
        {
            if (m == found)
                return m;
        }

        return Movie{};
    }


    /*
     Gets the movies from the watchlist
     */
    vector<Movie> getMovs() const { return movs; }

    /*
     Destructor for a watchlist
     */
    ~WatchList();
};

#endif // WATCHLIST_H
