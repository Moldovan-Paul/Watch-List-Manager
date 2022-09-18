#include "domain.h"
#include<string>
#include<sstream>
#include <utility>
#include <Windows.h>
#include <shellapi.h>
#include <cassert>
#include <vector>

Tutorial::Tutorial(std::string title, std::string pname, int duration, int likes, std::string link)
{
	this->title = std::move(title);
	this->pname = std::move(pname);
	this->duration = duration;
	this->likes = likes;
	this->link = std::move(link);
}

std::string Tutorial::getTitle() const
{
	return this->title;
}

std::string Tutorial::getLink() const
{
	return this->link;
}

std::string Tutorial::getPresenter() const
{
	return this->pname;
}

int Tutorial::getDuration() const
{
	return this->duration;
}

int Tutorial::getLikes() const
{
	return this->likes;
}

void Tutorial::increaseLikes()
{
	this->likes++;
}

std::string Tutorial::toString() const
{
	std::string prettyPrint;
	prettyPrint += this->title;
	prettyPrint += " " + this->pname;
	prettyPrint += " " + std::to_string(this->duration);
	prettyPrint += " " + std::to_string(this->likes);
	prettyPrint += " " + this->link + "\n";
	return prettyPrint;
}

void Tutorial::play() const
{
	ShellExecuteA(nullptr, nullptr, "chrome.exe", this->getLink().c_str(), nullptr, SW_SHOWMAXIMIZED);
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream& operator>>(std::istream& is, Tutorial& t)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	t.title = tokens[0];
	t.pname = tokens[1];
	t.duration = stod(tokens[2]);
	t.likes = stod(tokens[3]);
	t.link = tokens[4];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Tutorial& t)
{
	os << t.getTitle() << "," << t.getPresenter() << "," << std::to_string(t.getDuration()) << "," << std::to_string(t.getLikes()) << "," << t.getLink() << "\n";
	return os;

}

void Tutorial::domainTests()
{
    Tutorial t = Tutorial("a", "b", 2, 2, "c");
    assert(t.getLink() == "c");
    assert(t.getTitle() == "a");
    assert(t.getPresenter() == "b");
    t.increaseLikes();
    assert(t.likes == 3);
    assert(t.toString() == t.title + " " + t.pname + " " + std::to_string(t.duration) + " " + std::to_string(t.likes) +
            " " + t.link + "\n");
}


