#include "AdminDatabase.h"

#include "Exception.h"


void Repo::loadFromFile()
{
    ifstream f("testmovies.txt");
    Movie m;
    if(!f.is_open())
        throw Exception("Couldn't open the file!");

    while(f>>m)
        this->movies.push_back(m);

    f.close();
}

void Repo::writeToFile()
{
    ofstream g("testmovies.txt");

    if (!g.is_open())
        throw Exception("Couldn't open the file!");

    for (auto m : this->movies)
        g<<m;

    g.close();
}

void Repo::addMovie(const Movie& m)
{
    this->movies.push_back(m);
    writeToFile();
}

void Repo::delMovie(int poz)
{
    this->movies.erase(this->movies.begin() + poz);
    writeToFile();
}

void Repo::updateMovie(int poz, Movie& newM)
{
    this->movies.push_back(newM);
    this->movies.erase(this->movies.begin() + poz);
    writeToFile();
}

Movie Repo::findByTitleAndYear(const string& title, int yearOfRelease)
{
    vector<Movie> v = this->movies;

    Movie found {title, " ", yearOfRelease, 0, " ", 0};

    for (auto m : this->movies)
    {
        if (m == found)
            return m;
    }

    return Movie{};
}

int Repo::findPoz(const string& title, int yearOfRelease)
{
    vector<Movie> v = this->movies;

    Movie found {title, " ", yearOfRelease, 0, " ", 0};

    for (int i = 0; i < this->movies.size(); i++)
    {
        Movie m = v[i];
        if (m == found)
            return i;
    }
    return -1;
}

void Repo::filterByGenre(const string& genre)
{
    vector<Movie> v = this->movies;

    if (genre == "null")
        return;

    Movie m = this->movies.at(0);
    while(m.getGenre() != genre)
    {
        delMovie(0);
        m = this->movies.at(0);
    }

    for (int i = 1; i < this->movies.size();i++)
    {
        Movie m = this->movies.at(i);
        if (m.getGenre() != genre)
        {
            delMovie(i);
            i = i - 1;
        }

    }

}

void Repo::filterEverything(const string& s)
{
    vector<Movie> v = this->movies;

    Movie m = this->movies.at(0);

    while(strstr(m.getTitle().c_str(), s.c_str()) == NULL)
    {
        delMovie(0);
        m = this->movies.at(0);
    }

    for (int i = 1; i < this->movies.size();i++)
    {
        Movie m = this->movies.at(i);

        if (strstr(m.getTitle().c_str(), s.c_str()) == NULL)
        {
            delMovie(i);
            i = i - 1;
        }

    }
}

Movie Repo::getCurrentMovie()
{
    if (this->current == this->movies.size())
        this->current = 0;

    return this->movies[this->current];
}

void Repo::play()
{
    if (this->movies.size() == 0)
        return;

    this->current = 0;
    Movie currentMov = this->getCurrentMovie();
    //currentMov.playTrailer();
}

void Repo::next()
{
    if (this->movies.size() == 0)
        return;

    this->current++;
    Movie currentMov = this->getCurrentMovie();
    //currentMov.playTrailer();
}

Repo::~Repo()
{

}

