#include "wgapplet.h"
#include "qaction.h"
#include "qalgorithms.h"
#include "qicon.h"
#include "qmenu.h"
#include "qsystemtrayicon.h"
#include "ui_wgapplet.h"
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

void wgApplet::createActions() {

    auto settingsAction = new QAction("Settings...", this);
    connect(settingsAction, &QAction::triggered, this, &QWidget::show);
    actions.append(settingsAction);

    for (auto path : configs) {
        settingsAction = new QAction(path.c_str(), this);
        settingsAction->setData(QString::fromStdString(path.string()));
        connect(settingsAction, &QAction::triggered, this, &wgApplet::startConnection);
        actions.append(settingsAction);
    }

    return;
}


void wgApplet::createConfigs(std::string path) {
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        configs.push_back(entry);
    }
    return;
}

// Refresh all the configs in this->configs.
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
void wgApplet::startConnection(QAction* action) {
    auto config = action->data().toString().toStdString();
    auto command = std::string("wg-quick up ") + std::string(WIREGUARDPATH) + config;
    std::system(command.c_str());
    return;
}

// End a connection
void wgApplet::setConnection(std::string type, std::string config) {
    std::string command = "wg-quick " + type + " " + WIREGUARDPATH + config;
    std::system(command.c_str());
    return;
}

void wgApplet::setConnection();
