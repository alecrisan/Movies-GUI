#ifndef ADMINDATABASE_H
#define ADMINDATABASE_H


#include <fstream>
#include <stdio.h>
#include "Movie.h"
#include <vector>

class Repo
{
private:
    vector<Movie> movies;
    int current;

public:
    /*
     Default constructor for a repository
     */
    Repo() { this-> current = 0; }

    /*
     Constructor with parameters
     */
    Repo(vector<Movie>& mov): movies(mov) { this->current = 0; }

    /*
     Loads data from a file into the repository
     */
    void loadFromFile();

    /*
     Writes data from the repository to a file
     */
    void writeToFile();

    /*
     Adds a movie to the repository
     Input: m - Movie
     Output: the movie is added to the repository.
     */
    void addMovie(const Movie& m);

    /*
     Deletes a movie from the repository
     Input: poz - an integer, the position of the movie in the repo
     Output: the movie is deleted
     */
    void delMovie(int poz);


    /*
     Updates a movie from the repository
     Input: poz - an integer, the position of the old movie in the repo
            newM - the new movie
     Output: the movie is updated
     */
    void updateMovie(int poz, Movie& newM);


    /*
     Finds a movie by title and year of release
     Input: title - string
            yearOfRelease - integer
     Output: the movie that was found, or an "empty" movie (all fields empty), if nothing was found
     */
    Movie findByTitleAndYear(const string& title, int yearOfRelease);

    /*
     Finds the position of a movie in the repo
     Input: title - string
            yearOfRelease - integer
     Output: an integer representing the position or -1 if the movie wasn't found
     */
    int findPoz(const string& title, int yearOfRelease);

    /*
     Filters the movies by a given genre
     Input: genre - string
     Output: None
     */
    void filterByGenre(const string& genre);

    /*
     Filters the movies by a given string
     Input: s - string
     Output: None
     */
    void filterEverything(const string& s);

    /*
     Gets all the movies in the repo
     */
    vector<Movie> getMovies() const { return movies; }

    /*
     Returns the movie that is currently playing
     */
    Movie getCurrentMovie();

    /*
     Starts viewing the movies, one by one
     */
    void play();

    /*
     Moves to the next movie from the repo
     */
    void next();

    /*
     Destructor for Repo
     */
    ~Repo();

};

#endif // ADMINDATABASE_H
