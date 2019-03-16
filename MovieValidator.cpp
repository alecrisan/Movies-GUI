#include "MovieValidator.h"

MovieException::MovieException(vector<string> _messages): messages{_messages}
{

}
void MovieValidator::validate(const Movie& m)
{
    vector<string> errors;
    if(m.getYearOfRelease() < 0)
        errors.push_back("The year of release must be a positive number!\n");

    if(m.getnrLikes() < 0)
        errors.push_back("The number of likes must be a positive number!\n");

    if(m.getDuration() < 0)
        errors.push_back("The duration must be a positive number!\n");

    if(m.getTrailer().find("www") != 0)
        errors.push_back("The link must contain 'www'!\n");

    if (errors.size() > 0)
        throw MovieException(errors);
}
