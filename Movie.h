#ifndef MOVIE_H
#define MOVIE_H


#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class Movie
{
private:
    string title;
    string genre;
    int yearOfRelease;
    int nrLikes;
    string trailer;
    int duration;

public:
    /*
     Constructor for a movie
     */
    Movie();

    /*
     Constructor with parameters
     Input: title - string
            genre - string
            yearOfRelease - integer
            nrLikes - integer
            trailer - string (link)
            duration - integer (minutes)
     */
    Movie(const string& title, const string& genre, int yearOfRelease, int nrLikes, const string& trailer, int duration);


    /*
    Method that constructs a string containing a movie
    Input: None
    Output: var - string
    */
    string toString()
    {
        string var = "Title: " + this->title + " - ";
        var += "Genre: " + this->genre + " - ";
        var += "Year of release: " + to_string(this->yearOfRelease) + " - ";
        var += "Number of likes: " + to_string(this->nrLikes) + " - ";
        var += "Trailer: " + this->trailer + " - ";
        var += "Duration: " + to_string(this->duration);
        return var;
    }

    /*
     Overloads the "==" operator for 2 Movies
     */
    friend bool operator==(const Movie& m1, const Movie& m2);


    /*
     Overloads the '<' operator for the duration of a movie
     */
    friend bool operator<(const Movie& m, int a);

    /*
     Overloads the '<<' operator
     */
    friend ostream& operator<<(ostream& os, const Movie& m);

    /*
     Overloads the '>>' operator
     */
    friend istream& operator>>(istream& is, Movie& m);

    /*
     Gets the title of a movie
     Returns a string
     */
    string getTitle() const { return title; }

    /*
     Gets the genre of a movie
     Returns a string
     */
    string getGenre() const { return genre; }

    /*
     Gets the year of release of a movie
     Returns an integer
     */
    int getYearOfRelease() const { return yearOfRelease; }

    /*
     Gets the number of likes for a movie
     Returns an integer
     */
    int getnrLikes() const { return nrLikes; }

    /*
     Gets the trailer of the movie
     Returns a string (link)
     */
    string getTrailer() const { return trailer; }

    /*
     Gets the duration of the movie (in minutes)
     Returns an integer
     */
    int getDuration() const { return duration; }

    /*
     Increases a movie's number of likes
     */
    void increaseLike();

    /*
     Plays the current trailer: the page corresponding to the source link is opened in a browser.
     */
    void playTrailer();

    void setTitle(const string &tit) { this->title = tit;}

    /*
     Destructor for a Movie
     */
    ~Movie();
};

#endif // MOVIE_H
