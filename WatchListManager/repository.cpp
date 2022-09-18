#include "repository.h"
#include <assert.h>

int Repository::addRepo(const Tutorial& tutorial)
{
	if (find(tutorial.getTitle()) != -1)
		throw DuplicateTutorial();
	this->tutorials.push_back(tutorial);
	return 1;
}

int Repository::delRepo(const std::string& title)
{
	int size = this->getLength();
	int found = this->find(title);
	if (found == -1)
		throw InexistentTutorial();
	this->tutorials.erase(this->tutorials.begin() + found);
	return 1;
}

int Repository::updateRepo(const std::string& title, const Tutorial& tutorial)
{
	int size = this->getLength();
	int found = this->find(title);
	if (found == -1)
		throw InexistentTutorial();
	this->tutorials[found] = tutorial;
	return 1;
}

int Repository::getLength() const
{
	return this->tutorials.size();
}

Tutorial& Repository::getTutorial(int pos)
{
	return this->tutorials[pos];
}

int Repository::find(std::string title)
{
	int size = this->getLength();
	int pos = 0;
	for (auto tutorial : this->tutorials)
	{
		if (tutorial.getTitle() == title)
			return pos;
		pos++;
	}
	return -1;
}

std::vector<Tutorial> Repository::getRepo() const
{
	return this->tutorials;
}

Tutorial Repository::operator[](int pos)
{
	return this->tutorials[pos];
}

void Repository::readFromFile()
{
	std::ifstream f("in.txt");
	if (!f.is_open())
		return;
	Tutorial t;
	while (f >> t)
		addRepo(t);
	f.close();
}

void Repository::writeToFile()
{
	std::ofstream f("in.txt");
	if (!f.is_open())
		return;
	for (auto t : this->getRepo())
	{
		f << t;
	}
	f.close();
}

RepositoryException::RepositoryException()
{
}

RepositoryException::RepositoryException(const std::string& msg) : message{ msg }
{
}

const char* RepositoryException::what()
{
	return this->message.c_str();
}

const char* DuplicateTutorial::what()
{
	return "There is anoter tutorial with the same title.";
}

const char* InexistentTutorial::what()
{
	return "There is no tutorial matching.";
}



void Repository::repoTests()
{
	Repository repo;
	assert(repo.getLength() == 0);
	assert(repo.addRepo(Tutorial("a", "b", 2, 2, "c")) == 1);
	assert(repo.getLength() == 1);
	bool exceptionThrown = false;
	try
	{
		assert(repo.addRepo(Tutorial("a", "b", 2, 2, "c")) == 0);
	}
	catch (std::exception)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	exceptionThrown = false;
	try
	{
		assert(repo.delRepo("b") == 0);
	}
	catch (std::exception)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	assert(repo.delRepo("a") == 1);
	assert(repo.getLength() == 0);
	assert(repo.addRepo(Tutorial("x", "y", 2, 2, "z")) == 1);
	assert(repo.updateRepo("x", Tutorial("a", "b", 2, 2, "c")) == 1);
	exceptionThrown = false;
	try
	{
		assert(repo.updateRepo("x", Tutorial("a", "b", 2, 2, "c")) == 0);
	}
	catch (std::exception)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	assert(repo.find("a") != -1);
	assert(repo.find("x") == -1);
    assert(repo.getRepo().size() == 1);
    assert(repo.getTutorial(0).getTitle() == "a");
    assert(repo[0].getTitle() == "a");
}


