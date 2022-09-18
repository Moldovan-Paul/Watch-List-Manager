#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Assignment1112.h"
#include <qpainter>
#include "service.h"

class WatchListManager : public QMainWindow
{
    Q_OBJECT

public:
    WatchListManager(Service& service, QWidget* parent = Q_NULLPTR);
    WatchList* wl;
    std::vector<std::string> show_wl;

private:
    Ui::Assignment1112Class ui;
    Service &service;
    void populateList();
    void connect();
    void addTutorial();
    void deleteTutorial();
    void updateTutorial();

    void filterByPresenter();
    void addWL();
    void skipWL();
    void seeWL();
    void DeleteLikeTutorial();
    void deleteTutorialWL();
    void next();
    void populateWL();
    void resetTextFields();
    void saveToFile();
};
