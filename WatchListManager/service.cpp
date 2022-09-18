#include "service.h"

Service::Service()
{

}

Service::Service(const Repository& repository, WatchList* watchlist)
{
	this->repository = repository;
	this->watchlist = watchlist;
}

int Service::addService(const Tutorial& tutorial)
{
	return this->repository.addRepo(tutorial);
}

int Service::delService(const std::string& title)
{
	return this->repository.delRepo(title);
}

int Service::updateService(const std::string& title, const Tutorial& tutorial)
{
	return this->repository.updateRepo(title, tutorial);
}

int Service::getLengthService() const
{
	return this->repository.getLength();
}

std::vector<Tutorial> Service::getRepo() const
{
	return this->repository.getRepo();
}

int Service::addServiceWL(const Tutorial& tutorial)
{
	return this->watchlist->addWL(tutorial);
}

int Service::delServiceWL(const std::string& title)
{
	return this->watchlist->delWL(title);
}

int Service::getLengthWL() const
{
	return this->watchlist->getLengthWL();
}

WatchList* Service::getWL()
{
	return this->watchlist;
}



WatchList* Service::filterByPresenter(const std::string& presenter)
{
	WatchList* filter = new WatchList;
	for (const auto& tutorial : this->repository.getRepo())
	{
		if (tutorial.getPresenter() == presenter)
			filter->addWL(tutorial);
	}
	return filter;
}

void Service::likeTutorial(const std::string& title)
{
	this->repository.getTutorial(this->repository.find(title)).increaseLikes();
}

void Service::readFromFile()
{
	return this->repository.readFromFile();
}

void Service::writeToFile()
{
	return this->repository.writeToFile();
}

void Service::write()
{
	this->watchlist->write();
}

void Service::openWLfile()
{
	this->watchlist->displayWL();
}

void Service::serviceTests()
{
	Repository repo;
	WatchList* wl{};
	Service service(repo, wl);
	assert(service.addService(Tutorial("a", "b", 2, 2, "c")) == 1);
	bool exceptionThrown = false;
	try
	{
		assert(service.addService(Tutorial("a", "b", 2, 2, "c")) == 0);
	}
	catch (std::exception)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	assert(service.updateService("a", Tutorial("x", "y", 2, 2, "z")) == 1);
	exceptionThrown = false;
	try
	{
		assert(service.delService("a") == 0);
	}
	catch (std::exception)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	assert(service.delService("x") == 1);
    assert(service.getRepo().size() == 0);
    assert(service.addService(Tutorial("a", "b", 2, 2, "c")) == 1);
    assert(service.addService(Tutorial("b", "b", 2, 2, "c")) == 1);
    assert(service.addService(Tutorial("c", "b", 2, 2, "c")) == 1);
}



