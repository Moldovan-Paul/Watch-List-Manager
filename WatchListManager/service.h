#pragma once
#include "repository.h"
#include "watchlist.h"

class Service
{
private:
	Repository repository;
	WatchList* watchlist;
public:
	Service();
	explicit Service(const Repository& repository, WatchList* watchlist);
    ///Adds a tutorial to the corresponding repository
	int addService(const Tutorial& tutorial);
    ///Deletes a tutorial from the corresponding repository
	int delService(const std::string& title);
    ///Updates a tutorial within the corresponding repository
	int updateService(const std::string& title, const Tutorial& tutorial);
	int getLengthService() const;
	std::vector<Tutorial> getRepo() const;

    ///Adds a tutorial to the watch list
	int addServiceWL(const Tutorial& tutorial);
    ///Deletes a tutorial from the watch list
	int delServiceWL(const std::string& title);
	int getLengthWL() const;
	WatchList* getWL();
    ///Creates and returns a WatchList object containing only the tutorials which have in common a given presenter
	WatchList* filterByPresenter(const std::string& presenter);
    ///Increments number of likes by 1 of a tutorial given by title
	void likeTutorial(const std::string& title);

	void readFromFile();
	void writeToFile();
	void write();
	void openWLfile();

	void serviceTests();
};
