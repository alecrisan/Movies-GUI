#include "CSVWatchList.h"
#include "Exception.h"

void CSVWatchList::writeToFile()
{
    ofstream g(this->filename);

    if (!g.is_open())
        throw Exception("The file could not be opened!");

    for (auto m : this->movs)
    {
        g << m;
    }

    g.close();
}

void CSVWatchList::displayWatchList() const
{
    system(("open " + this->filename).c_str());
}
