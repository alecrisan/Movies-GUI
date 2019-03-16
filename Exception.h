#ifndef EXCEPTION_H
#define EXCEPTION_H


#include <string>
#include <exception>

using namespace std;
class Exception: public exception
{
private:
    string message;

public:
    /*
     Constructor for an Exception
     */
    Exception(const string &mess);

    virtual const char* what();

};

#endif // EXCEPTION_H
