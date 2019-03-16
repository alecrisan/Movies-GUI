#include "Exception.h"


Exception::Exception(const string & mess) : message(mess)
{
}

const char* Exception::what()
{
    return message.c_str();
}
