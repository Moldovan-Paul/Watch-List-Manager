#pragma once
#include "dynamicvector.h"
#include<vector>

class WatchList
{
protected:
	std::vector<Tutorial> tutorials;
	int current = 0;
public:
	WatchList() = default;
	int addWL(const Tutorial& tutorial);
	int delWL(const std::string& title);
	int findWL(const std::string& title);
	void incrementCurrent();
	void playCurrent();
	int getLengthWL() const;
	Tutorial getTutorial();
	virtual void write();
	virtual void displayWL();

    Tutorial operator[](int pos);
	static void watchlistTests();
};