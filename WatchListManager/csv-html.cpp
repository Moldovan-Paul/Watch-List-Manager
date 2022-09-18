#include "csv-html.h"
#include <fstream>
#include <windows.h>
#include <shellapi.h>

HTMLwatchList::HTMLwatchList(std::string filepath)
{
	this->filepath = filepath;
}

void HTMLwatchList::write()
{
	std::ofstream f(this->filepath);
	if (f.is_open())
	{
		f << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchlist</title>\n</head>\n<body>\n<table border = \"1\">\n<tr>\n<td>Title</td>\n<td>Presenter</td>\n<td>Duration</td>\n<td>Likes</td>\n<td>Link</td>\n</tr>\n";
		for (auto t : this->tutorials)
		{
			f << "<tr>\n";
			f << "<td>" << t.getTitle() << "</td>\n";
			f << "<td>" << t.getPresenter() << "</td>\n";
			f << "<td>" << t.getDuration() << "</td>\n";
			f << "<td>" << t.getLikes() << "</td>\n";
			f << "<td>" << t.getLink() << "</td>\n";
			f << "</tr>\n";
		}
		f << "</table>\n</body>\n</html>\n";
		f.close();
	}
}



void HTMLwatchList::displayWL()
{
	std::string command = this->filepath;
	ShellExecute(0, 0, std::wstring(command.begin(), command.end()).c_str(), 0, 0, SW_SHOW);
}


CSVwatchList::CSVwatchList(std::string filepath)
{
	this->filepath = filepath;
}

void CSVwatchList::write()
{
	std::ofstream f(this->filepath);

	for (auto t : this->tutorials)
	{
		f << t;
	}
	f.close();
}

void CSVwatchList::displayWL()
{
	std::string command = "start excel.exe " + this->filepath;
	system(command.c_str());

}

