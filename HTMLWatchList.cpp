
#include "HTMLWatchList.h"
#include "Exception.h"

void HTMLWatchList::writeToFile()
{
    ofstream g(this->filename);

    if (!g.is_open())
        throw Exception("The file could not be opened!");

    g << "<!DOCTYPE html>\n" << "<html>\n" << "<head>\n" << "<title>WatchList</title>\n" << "</head>\n" << "<body>\n" << "<table border=\"1\">" <<
    "<tr>\n" << "<td>Title</td>\n" << "<td>Genre</td>\n" << "<td>Year</td>\n" << "<td>Likes</td>\n" << "<td>Trailer</td>\n" << "<td>Duration</td>\n" << "</tr>\n";

    for (int i = 0; i < this->movs.size(); i++)
    {
        Movie m = this->movs.at(i);
        g << "<tr>\n" << "<td>" << m.getTitle() << "</td>\n" << "<td>" << m.getGenre() << "</td>\n" << "<td>" << m.getYearOfRelease() << "</td>\n" << "<td>" << m.getnrLikes() << "</td>\n" << "<td>" << m.getTrailer() << "</td>\n" << "<td>" << m.getDuration() << "</td>\n" << "<td><a href = \"https://www.youtube.com/watch?v=2fngvQS_PmQ\">Link</a></td>\n";
    }

    g << "</table\n" << "</body>\n" << "</html>";

    g.close();
}

void HTMLWatchList::displayWatchList() const
{
    system(("open " + this->filename).c_str());
}
