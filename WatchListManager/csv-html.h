#pragma once
#include "watchlist.h"
class HTMLwatchList : public WatchList
{
private:
	std::string filepath;
public:
	HTMLwatchList() = default;
	HTMLwatchList(std::string filepath);
	/// <summary>
	/// Overridden function used for writing html code to a preexisting file
	/// </summary>
	void write();
	/// <summary>
	/// Opens html file containing watch list in default browser
	/// </summary>
	void displayWL();
};


class CSVwatchList : public WatchList
{
private:
	std::string filepath;
public:
	CSVwatchList() = default; 
	CSVwatchList(std::string filepath);
	/// <summary>
	/// Overridden function used for writing the tutorials in an excel file
	/// </summary>
	void write();
	/// <summary>
	/// Opens excel file containing watch list
	/// </summary>
	void displayWL();
};