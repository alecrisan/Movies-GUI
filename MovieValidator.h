#ifndef MOVIEVALIDATOR_H
#define MOVIEVALIDATOR_H


#include <stdio.h>
#include "Movie.h"

class MovieException
{
private:
    vector<string> messages;

public:

    /*
     Constructor with parameters for a MovieException
     */
    MovieException(vector<string> _messages);

    /*
     Gets the error messages
     Returns a vector of strings
     */
    vector<string> getErrorMsg() const {return this->messages; }

};

class MovieValidator
{

public:

    /*
     Default constructor for a MovieValidator
     */
    MovieValidator() {}

    /*
     Checks whether the movie is valid or not
     */
    static void validate(const Movie& m);

};


#endif // MOVIEVALIDATOR_H
