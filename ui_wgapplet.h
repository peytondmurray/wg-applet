/********************************************************************************
** Form generated from reading UI file 'wgapplet.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGAPPLET_H
#define UI_WGAPPLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wgApplet
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wgApplet)
    {
        if (wgApplet->objectName().isEmpty())
            wgApplet->setObjectName(QString::fromUtf8("wgApplet"));
        wgApplet->resize(800, 600);
        centralwidget = new QWidget(wgApplet);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        wgApplet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wgApplet);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        wgApplet->setMenuBar(menubar);
        statusbar = new QStatusBar(wgApplet);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wgApplet->setStatusBar(statusbar);

        retranslateUi(wgApplet);

        QMetaObject::connectSlotsByName(wgApplet);
    } // setupUi

    void retranslateUi(QMainWindow *wgApplet)
    {
        wgApplet->setWindowTitle(QCoreApplication::translate("wgApplet", "wgApplet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wgApplet: public Ui_wgApplet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGAPPLET_H
