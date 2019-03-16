#include "Movie.h"

Movie::Movie(): title(""), genre(""), yearOfRelease(0), nrLikes(0), trailer(""), duration(0) {}

Movie::Movie(const string& title, const string& genre, int yearOfRelease, int nrLikes, const string& trailer, int duration)
{
    this->title = title;
    this->genre = genre;
    this->yearOfRelease = yearOfRelease;
    this->nrLikes = nrLikes;
    this->trailer = trailer;
    this->duration = duration;
}

bool operator==(const Movie& m1, const Movie& m2)
{
    return (m1.getTitle() == m2.getTitle() && m1.getYearOfRelease() == m2.getYearOfRelease());
}

bool operator<(const Movie& m, int a)
{
    return (m.getDuration() < a);
}

istream& operator>>(istream& is, Movie& m)
{
    string line;
    getline(is, line);
    stringstream ss(line);
    string token;
    vector<string> temp;
    while (getline(ss, token, ','))
        temp.push_back(token);

    if (temp.size() != 6)
        return is;


    m.title = temp[0];
    m.genre = temp[1];
    m.yearOfRelease = stoi(temp[2]);
    m.nrLikes = stoi(temp[3]);
    m.trailer = temp[4];
    m.duration = stoi(temp[5]);

    return is;


}

ostream& operator<<(ostream& os, const Movie& m)
{
    os << m.title << "," << m.genre << "," << m.yearOfRelease << "," << m.nrLikes << "," << m.trailer << "," << m.duration<<'\n';
    return os;
}

void Movie::increaseLike()
{
    this->nrLikes = this->nrLikes + 1;
}

void Movie::playTrailer()
{
    system(("open " + this->getTrailer()).c_str());
}

Movie::~Movie()
{

}
