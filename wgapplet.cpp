#include "wgapplet.h"
#include "qaction.h"
#include "qalgorithms.h"
#include "qicon.h"
#include "qmenu.h"
#include "qsystemtrayicon.h"
#include "ui_wgapplet.h"
#include "wgaction.h"
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

#define WIREGUARDPATH "/etc/wireguard/"


wgApplet::wgApplet(QWidget *parent) : QMainWindow(parent), ui(new Ui::wgApplet)
{
    ui->setupUi(this);
    createTrayIcon();
    trayIcon->show();
    setWindowTitle("Settings");
}

wgApplet::~wgApplet()
{
    delete ui;
}

void wgApplet::createTrayIcon() {

    menu = new QMenu(this);


    createConfigs(WIREGUARDPATH);
    createActions();
    menu->addSeparator();
    menu->addActions(actions);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon());
    trayIcon->setContextMenu(menu);
    return;
}

QMenu* wgApplet::createMenu() {


}

void wgApplet::createActions() {

    auto settingsAction = new QAction("Settings...", this);
    connect(settingsAction, &QAction::triggered, this, &QWidget::show);
    actions.append(settingsAction);

    settingsAction = new QAction("Disconnect", this);
    connect(settingsAction, &QAction::triggered, this, &wgApplet::stop);

    for (auto path : configs) {
        settingsAction = new wgAction(this, path.c_str());
        settingsAction->setData(QString::fromStdString(path.string()));
        connect(settingsAction, &QAction::triggered, this, &wgApplet::start);
        actions.append(settingsAction);
    }

    return;
}

/**
 * Get the list of config files from the specified path.
 *
 * @param path Path to the wireguard configs; usually this is /etc/wireguard/
 */
void wgApplet::createConfigs(std::string path) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        configs.push_back(entry);
    }
    return;
}

void wgApplet::refreshConfigs(std::string path) {
    configs.clear();
    createConfigs(path);
}

void wgApplet::refreshActions() {
    qDeleteAll(actions);
    actions.clear();
    createActions();
    return;
}

// Start a connection
void wgApplet::start(QAction* action) {
    setConnection("up", action->data().toString().toStdString());
    return;
}

// Stop a connection
void wgApplet::stop(QAction* action) {
    setConnection("down", action->data().toString().toStdString());
    return;
}

// Compose and execute the command to start or stop a connection
void wgApplet::setConnection(std::string option, std::string config) {
    std::string command = "wg-quick " + option + " " + WIREGUARDPATH + config;
    std::system(command.c_str());
    return;
}
