#include "WatchList.h"

WatchList::WatchList()
{
    this->current = 0;
}

void WatchList::add(const Movie& m)
{
    this->movs.push_back(m);

}

void WatchList::del(const string& title, int yearOfRelease)
{
    int poz = this->findPoz(title, yearOfRelease);
    this->movs.erase(this->movs.begin() + poz);
}

int WatchList::findPoz(const string& title, int yearOfRelease)
{
    vector<Movie> v = this->movs;

    Movie found {title, " ", yearOfRelease, 0, " ", 0};

    for (int i = 0; i < this->movs.size(); i++)
    {
        Movie m = v[i];
        if (m == found)
            return i;
    }
    return -1;
}

WatchList::~WatchList()
{

}
