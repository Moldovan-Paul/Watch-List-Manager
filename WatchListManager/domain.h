#pragma once
#include <string>
#include <fstream>

class Tutorial
{
private:
	std::string title;
	std::string pname;
	int duration;
	int likes;
	std::string link;
public:
	explicit Tutorial(std::string title = "", std::string pname = "", int duration = 0, int likes = 0, std::string link = "");
	std::string getTitle() const;
	std::string getLink() const;
	std::string getPresenter() const;
	int getDuration() const;
	int getLikes() const;
    ///Increments number of likes
	void increaseLikes();
    ///Converts a tutorial object to a printable string
	std::string toString() const;
    ///Opens tutorial link in the browser
	void play() const;
    static void domainTests();
	friend std::istream& operator>>(std::istream& is, Tutorial& c);
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& c);

};