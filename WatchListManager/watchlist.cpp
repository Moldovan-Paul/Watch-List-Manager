#include "watchlist.h"
#include<cassert>

int WatchList::addWL(const Tutorial& tutorial)
{
	if (findWL(tutorial.getTitle()) != -1)
		return 0;
	this->tutorials.push_back(tutorial);
	return 1;
}

int WatchList::delWL(const std::string& title)
{
	int found = findWL(title);
	if (found == -1)
		return 0;
	this->tutorials.erase(this->tutorials.begin() + found);
	return 1;
}

int WatchList::findWL(const std::string& title)
{
	int pos = 0;
	for (const auto& tutorial : this->tutorials)
	{
		if (tutorial.getTitle() == title)
			return pos;
		pos++;
	}
	return -1;
}

void WatchList::incrementCurrent()
{
	if (this->current == this->getLengthWL() - 1)
	{
		this->current = -1;
	}
	this->current++;
}

void WatchList::playCurrent()
{
	this->tutorials[current].play();
}

int WatchList::getLengthWL() const
{
	return this->tutorials.size();
}

Tutorial WatchList::getTutorial()
{
	return this->tutorials[this->current];
}

void WatchList::write()
{
}

void WatchList::displayWL()
{
}

Tutorial WatchList::operator[](int pos)
{
	return this->tutorials[pos];
}

/*void WatchList::watchlistTests()
{
	WatchList wl;
	assert(wl.getLengthWL() == 0);
	assert(wl.addWL(Tutorial("a", "b", 2, 2, "c")) == 1);
	assert(wl.getLengthWL() == 1);
	assert(wl.addWL(Tutorial("a", "b", 2, 2, "c")) == 0);
	assert(wl.delWL("b") == 0);
	assert(wl.delWL("a") == 1);
	assert(wl.getLengthWL() == 0);
    wl.incrementCurrent();
    assert(wl.current == 1);
    assert(wl.addWL(Tutorial("a", "b", 2, 2, "c")) == 1);
    assert(wl.addWL(Tutorial("z", "b", 2, 2, "c")) == 1);
    assert(wl.getTutorial().getTitle() == "z");
    assert(wl[0].getTitle() == "a");
    wl.incrementCurrent();
    assert(wl.current == 0);
}*/
