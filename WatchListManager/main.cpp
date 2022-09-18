#include "GUI.h"
#include <QtWidgets/QApplication>
#include "watchlist.h"
#include "dynamicvector.h"
#include <iostream>
#include "csv-html.h"

int main(int argc, char *argv[])
{
	DynamicVector<Tutorial> dvec;
	dvec.dynamicVectorTests();
	Repository repo;
	repo.repoTests();
	std::string filepath;
	/*filepath = "save.csv";
	CSVwatchList cwl(filepath);
	Service service(repo, &cwl);
	QApplication a(argc, argv);
	WatchListManager w(service);*/
	filepath = "save.html";
	HTMLwatchList hwl(filepath);
	Service service(repo, &hwl);
	service.serviceTests();
	QApplication a(argc, argv);
	WatchListManager w(service);
	w.show();
	return a.exec();
}
