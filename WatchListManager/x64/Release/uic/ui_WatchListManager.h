/********************************************************************************
** Form generated from reading UI file 'Assignment1112.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT1112_H
#define UI_ASSIGNMENT1112_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment1112Class
{
public:
    QWidget *centralWidget;
    QListWidget *tutorial_list;
    QListWidget *watchlist;
    QLineEdit *title;
    QLineEdit *updatedtitle;
    QLineEdit *presenter;
    QLineEdit *duration;
    QLineEdit *likes;
    QLineEdit *link;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *add_button;
    QPushButton *update_button;
    QPushButton *delete_button;
    QLineEdit *filter_by_presenter;
    QPushButton *add_wl_button;
    QPushButton *skip_button;
    QPushButton *like;
    QPushButton *skip;
    QPushButton *saveandopen;
    QPushButton *fbp_button;
    QPushButton *see_wl;
    QPushButton *delete_current;
    QLabel *test;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment1112Class)
    {
        if (Assignment1112Class->objectName().isEmpty())
            Assignment1112Class->setObjectName(QString::fromUtf8("Assignment1112Class"));
        Assignment1112Class->resize(847, 620);
        centralWidget = new QWidget(Assignment1112Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tutorial_list = new QListWidget(centralWidget);
        tutorial_list->setObjectName(QString::fromUtf8("tutorial_list"));
        tutorial_list->setGeometry(QRect(10, 10, 401, 251));
        watchlist = new QListWidget(centralWidget);
        watchlist->setObjectName(QString::fromUtf8("watchlist"));
        watchlist->setGeometry(QRect(430, 10, 401, 251));
        title = new QLineEdit(centralWidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(160, 280, 251, 21));
        updatedtitle = new QLineEdit(centralWidget);
        updatedtitle->setObjectName(QString::fromUtf8("updatedtitle"));
        updatedtitle->setGeometry(QRect(160, 320, 251, 21));
        presenter = new QLineEdit(centralWidget);
        presenter->setObjectName(QString::fromUtf8("presenter"));
        presenter->setGeometry(QRect(160, 360, 251, 21));
        duration = new QLineEdit(centralWidget);
        duration->setObjectName(QString::fromUtf8("duration"));
        duration->setGeometry(QRect(160, 400, 251, 21));
        likes = new QLineEdit(centralWidget);
        likes->setObjectName(QString::fromUtf8("likes"));
        likes->setGeometry(QRect(160, 440, 251, 21));
        link = new QLineEdit(centralWidget);
        link->setObjectName(QString::fromUtf8("link"));
        link->setGeometry(QRect(160, 480, 251, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 280, 41, 16));
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 320, 121, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 360, 81, 20));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 400, 81, 20));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 440, 41, 20));
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 480, 41, 20));
        label_6->setFont(font);
        add_button = new QPushButton(centralWidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(50, 520, 75, 24));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        add_button->setFont(font1);
        update_button = new QPushButton(centralWidget);
        update_button->setObjectName(QString::fromUtf8("update_button"));
        update_button->setGeometry(QRect(180, 520, 75, 24));
        delete_button = new QPushButton(centralWidget);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(310, 520, 75, 24));
        filter_by_presenter = new QLineEdit(centralWidget);
        filter_by_presenter->setObjectName(QString::fromUtf8("filter_by_presenter"));
        filter_by_presenter->setGeometry(QRect(650, 280, 151, 21));
        add_wl_button = new QPushButton(centralWidget);
        add_wl_button->setObjectName(QString::fromUtf8("add_wl_button"));
        add_wl_button->setGeometry(QRect(490, 320, 75, 24));
        add_wl_button->setFont(font1);
        skip_button = new QPushButton(centralWidget);
        skip_button->setObjectName(QString::fromUtf8("skip_button"));
        skip_button->setGeometry(QRect(680, 320, 75, 24));
        skip_button->setFont(font1);
        like = new QPushButton(centralWidget);
        like->setObjectName(QString::fromUtf8("like"));
        like->setGeometry(QRect(660, 450, 151, 24));
        like->setFont(font1);
        skip = new QPushButton(centralWidget);
        skip->setObjectName(QString::fromUtf8("skip"));
        skip->setGeometry(QRect(680, 370, 75, 21));
        skip->setFont(font1);
        saveandopen = new QPushButton(centralWidget);
        saveandopen->setObjectName(QString::fromUtf8("saveandopen"));
        saveandopen->setGeometry(QRect(560, 530, 151, 21));
        saveandopen->setFont(font1);
        fbp_button = new QPushButton(centralWidget);
        fbp_button->setObjectName(QString::fromUtf8("fbp_button"));
        fbp_button->setGeometry(QRect(460, 280, 151, 24));
        fbp_button->setFont(font1);
        see_wl = new QPushButton(centralWidget);
        see_wl->setObjectName(QString::fromUtf8("see_wl"));
        see_wl->setGeometry(QRect(490, 370, 151, 24));
        see_wl->setFont(font1);
        delete_current = new QPushButton(centralWidget);
        delete_current->setObjectName(QString::fromUtf8("delete_current"));
        delete_current->setGeometry(QRect(450, 450, 151, 24));
        delete_current->setFont(font1);
        test = new QLabel(centralWidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(430, 330, 49, 16));
        Assignment1112Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment1112Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 22));
        Assignment1112Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment1112Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment1112Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment1112Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment1112Class->setStatusBar(statusBar);

        retranslateUi(Assignment1112Class);

        QMetaObject::connectSlotsByName(Assignment1112Class);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment1112Class)
    {
        Assignment1112Class->setWindowTitle(QCoreApplication::translate("Assignment1112Class", "Assignment1112", nullptr));
        label->setText(QCoreApplication::translate("Assignment1112Class", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("Assignment1112Class", "Updated Title", nullptr));
        label_3->setText(QCoreApplication::translate("Assignment1112Class", "Presenter", nullptr));
        label_4->setText(QCoreApplication::translate("Assignment1112Class", "Duration", nullptr));
        label_5->setText(QCoreApplication::translate("Assignment1112Class", "Likes", nullptr));
        label_6->setText(QCoreApplication::translate("Assignment1112Class", "Link", nullptr));
        add_button->setText(QCoreApplication::translate("Assignment1112Class", "Add", nullptr));
        update_button->setText(QCoreApplication::translate("Assignment1112Class", "Update", nullptr));
        delete_button->setText(QCoreApplication::translate("Assignment1112Class", "Delete", nullptr));
        add_wl_button->setText(QCoreApplication::translate("Assignment1112Class", "Add", nullptr));
        skip_button->setText(QCoreApplication::translate("Assignment1112Class", "Skip", nullptr));
        like->setText(QCoreApplication::translate("Assignment1112Class", "Delete and like current", nullptr));
        skip->setText(QCoreApplication::translate("Assignment1112Class", "Next", nullptr));
        saveandopen->setText(QCoreApplication::translate("Assignment1112Class", "Save watchlist", nullptr));
        fbp_button->setText(QCoreApplication::translate("Assignment1112Class", "Filter by presenter", nullptr));
        see_wl->setText(QCoreApplication::translate("Assignment1112Class", "See watchlist", nullptr));
        delete_current->setText(QCoreApplication::translate("Assignment1112Class", "Delete current", nullptr));
        test->setText(QCoreApplication::translate("Assignment1112Class", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment1112Class: public Ui_Assignment1112Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT1112_H
