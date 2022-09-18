#pragma once
#include "dynamicvector.h"
#include "domain.h"
#include<vector>
#include<fstream>

class Repository
{
private:
	std::vector<Tutorial> tutorials;
public:
	Repository() = default;
    ///Adds a tutorial to the repository and returns true if the operation was successful, or false otherwise
	int addRepo(const Tutorial& tutorial);
    ///Deletes a tutorial from the repository and returns true if the operation was successful, or false otherwise
	int delRepo(const std::string& title);
    ///Updates a tutorial that exists in the repository and returns true if the operation was successful,
    /// or false if the tutorial doesn't exist
	int updateRepo(const std::string& title, const Tutorial& tutorial);
	int getLength() const;
	Tutorial& getTutorial(int pos);
    ///Returns the position of a tutorial given by name or -1 if it does not exist in the repository
	int find(std::string title);
	std::vector<Tutorial> getRepo() const;
	Tutorial operator[](int pos);
	/// <summary>
	/// Reads a tutorial from a file
	/// </summary>
	void readFromFile();
	/// <summary>
	/// Writes all tutorials to a .txt file
	/// </summary>
	void writeToFile();
	void repoTests();
};


class RepositoryException : public std::exception
{
protected:
	std::string message;
public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}
	/// <summary>
	/// Used for printing each exception
	/// </summary>
	virtual const char* what();

};

class DuplicateTutorial : public RepositoryException
{
public:

	const char* what();
};

class InexistentTutorial : public RepositoryException
{
public:

	const char* what();

};