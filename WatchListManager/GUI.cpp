#include "GUI.h"

WatchListManager::WatchListManager(Service& service, QWidget* parent)
    : QMainWindow(parent), service(service)
{
    ui.setupUi(this);
    this->service.readFromFile();
    this->connect();
    this->populateList();
}

void WatchListManager::populateList()
{
    std::vector<Tutorial> result = this->service.getRepo();
    std::string aux_string;
    int i;
    for (i = 0; i < result.size(); i++) {
        aux_string = "";
        aux_string += result[i].getTitle();
        aux_string += " ";
        aux_string += result[i].getPresenter();
        aux_string += " ";
        aux_string += std::to_string(result[i].getDuration());
        aux_string += " ";
        aux_string += std::to_string(result[i].getLikes());
        aux_string += " ";
        aux_string += result[i].getLink();
        aux_string += "\n";
        this->ui.tutorial_list->addItem(QString::fromStdString(aux_string));
    }
}

void WatchListManager::connect()
{
    QObject::connect(this->ui.add_button, &QPushButton::clicked, this, &WatchListManager::addTutorial);
    QObject::connect(this->ui.delete_button, &QPushButton::clicked, this, &WatchListManager::deleteTutorial);
    QObject::connect(this->ui.update_button, &QPushButton::clicked, this, &WatchListManager::updateTutorial);
    QObject::connect(this->ui.fbp_button, &QPushButton::clicked, this, &WatchListManager::filterByPresenter);
    QObject::connect(this->ui.add_wl_button, &QPushButton::clicked, this, &WatchListManager::addWL);
    QObject::connect(this->ui.skip_button, &QPushButton::clicked, this, &WatchListManager::skipWL);
    QObject::connect(this->ui.see_wl, &QPushButton::clicked, this, &WatchListManager::seeWL);
    QObject::connect(this->ui.delete_current, &QPushButton::clicked, this, &WatchListManager::deleteTutorialWL);
    QObject::connect(this->ui.like, &QPushButton::clicked, this, &WatchListManager::DeleteLikeTutorial);
    QObject::connect(this->ui.skip, &QPushButton::clicked, this, &WatchListManager::next);
    QObject::connect(this->ui.saveandopen, &QPushButton::clicked, this, &WatchListManager::saveToFile);
}

void WatchListManager::addTutorial()
{
    std::string title = this->ui.title->text().toStdString();
    std::string presenter = this->ui.presenter->text().toStdString();
    std::string duration = this->ui.duration->text().toStdString();
    std::string likes = this->ui.likes->text().toStdString();
    std::string link = this->ui.link->text().toStdString();
    if (this->service.addService(Tutorial(title, presenter, std::stoi(duration), std::stoi(likes), link)));
    this->ui.tutorial_list->addItem(QString::fromStdString(title + " " + presenter + " " + duration + " " + likes + " " + link + "\n"));
    this->service.writeToFile();
    this->resetTextFields();
}

void WatchListManager::deleteTutorial()
{
    std::string title = this->ui.title->text().toStdString();
    if (this->service.delService(title))
    {
        this->ui.tutorial_list->clear();
        this->populateList();
    }
    this->service.writeToFile();
    this->resetTextFields();
}

void WatchListManager::updateTutorial()
{
    std::string title = this->ui.title->text().toStdString();
    std::string updatedtitle = this->ui.updatedtitle->text().toStdString();
    std::string updatedpresenter = this->ui.presenter->text().toStdString();
    std::string updatedduration = this->ui.duration->text().toStdString();
    std::string updatedlikes = this->ui.likes->text().toStdString();
    std::string updatedlink = this->ui.link->text().toStdString();
    if (this->service.updateService(title, Tutorial(updatedtitle, updatedpresenter, std::stoi(updatedduration), std::stoi(updatedlikes), updatedlink)));
    {
        this->ui.tutorial_list->clear();
        this->populateList();
    }
    this->service.writeToFile();
    this->resetTextFields();
}

void WatchListManager::filterByPresenter()
{
    std::string presenter = this->ui.filter_by_presenter->text().toStdString();
    std::vector<Tutorial> t;
    if (this->ui.filter_by_presenter->text().isEmpty())
    {
        this->wl = new WatchList;
        for (const auto& it : this->service.getRepo())
        {
            this->wl->addWL(it);
        }
    }
    else
        this->wl = this->service.filterByPresenter(presenter);
    this->wl->playCurrent();
}

void WatchListManager::addWL()
{
    if (this->wl->getLengthWL())
    {
        std::string title = this->wl->getTutorial().getTitle();
        std::string presenter = this->wl->getTutorial().getPresenter();
        std::string duration = std::to_string(this->wl->getTutorial().getDuration());
        std::string likes = std::to_string(this->wl->getTutorial().getLikes());
        std::string link = this->wl->getTutorial().getLink();
        this->ui.watchlist->addItem(QString::fromStdString(title + " " + presenter + " " + duration + " " + likes + " " + link + "\n"));
        this->service.addServiceWL(this->wl->getTutorial());
        this->show_wl.push_back(title + " " + presenter + " " + duration + " " + likes + " " + link + "\n");
        this->wl->delWL(title);
        this->wl->playCurrent();
        this->service.write();
    }

}

void WatchListManager::skipWL()
{
    if (this->wl->getLengthWL())
    {
        this->wl->incrementCurrent();
        this->wl->playCurrent();
    }
}

void WatchListManager::seeWL()
{
    if (this->service.getLengthWL())
    {
        delete this->wl;
        this->service.getWL()->playCurrent();
    }
}

void WatchListManager::DeleteLikeTutorial()
{
    if (this->service.getLengthWL())
    {
        this->service.likeTutorial(this->service.getWL()->getTutorial().getTitle());
        this->ui.tutorial_list->clear();
        this->service.delServiceWL(this->service.getWL()->getTutorial().getTitle());
        this->show_wl.erase(this->show_wl.begin());
        this->populateList();
        this->populateWL();
    }
    if (this->service.getLengthWL())
    {
        this->service.getWL()->incrementCurrent();
        this->service.getWL()->playCurrent();
        this->service.write();
    }

}

void WatchListManager::deleteTutorialWL()
{
    if (this->service.getLengthWL())
    {
        this->service.delServiceWL(this->service.getWL()->getTutorial().getTitle());
        this->show_wl.erase(this->show_wl.begin());
        this->populateWL();
    }
    if (this->service.getLengthWL())
    {
        this->service.getWL()->incrementCurrent();
        this->service.getWL()->playCurrent();
        this->service.write();
    }
}

void WatchListManager::next()
{
    if (this->service.getLengthWL())
    {
        this->service.getWL()->incrementCurrent();
        this->service.getWL()->playCurrent();
    }
}

void WatchListManager::populateWL()
{
    int i;
    this->ui.watchlist->clear();
    for (i = 0; i < this->show_wl.size(); i++)
        this->ui.watchlist->addItem(QString::fromStdString(this->show_wl[i]));

}

void WatchListManager::resetTextFields() {
    this->ui.title->clear();
    this->ui.updatedtitle->clear();
    this->ui.presenter->clear();
    this->ui.duration->clear();
    this->ui.likes->clear();
    this->ui.link->clear();
}

void WatchListManager::saveToFile()
{
    this->service.openWLfile();
}