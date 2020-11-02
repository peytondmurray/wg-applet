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
#define ICONPATH "/home/pdmurray/Desktop/workspace/wg-applet/lock.svg"


wgApplet::wgApplet(QWidget *parent) : QMainWindow(parent), ui(new Ui::wgApplet)
{
    ui->setupUi(this);
    createTrayIcon();
    trayIcon->show();
    setWindowTitle("Settings");
    this->hide();
}

wgApplet::~wgApplet()
{
    delete ui;
}

void wgApplet::createTrayIcon() {

    menu = createMenu();
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(ICONPATH));
    trayIcon->setContextMenu(menu);
    return;
}

QMenu* wgApplet::createMenu() {
    auto m = new QMenu();
    createActions();
    m->addSeparator();
    for (const auto &action : actions) {
        m->addAction(action);
    }
    return m;
}

void wgApplet::createActions() {

    auto settingsAction = new wgAction("Settings...", this);
    connect(settingsAction, &wgAction::triggered, this, &QWidget::show);
    actions.append(settingsAction);

    settingsAction = new wgAction("Disconnect", this);
    connect(settingsAction, &wgAction::triggered, this, &wgApplet::stop);

    //for (auto path : configs) {
        //settingsAction = new wgAction(path.string(), this, path.c_str());
        //connect(settingsAction, &wgAction::triggered, this, &wgApplet::start);
        //actions.append(settingsAction);
    //}

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
void wgApplet::start(bool checked) {
    //setConnection("up", action->getConfig().toStdString());
    return;
}

// Stop a connection
//void wgApplet::stop(bool checked) {
void wgApplet::stop(QString checked) {
    std::cout << "checked: " << checked.toStdString() << std::endl;
    //setConnection("down", action->getConfig().toStdString());
    return;
}

// Compose and execute the command to start or stop a connection
void wgApplet::setConnection(std::string option, std::string config) {
    std::string command = "wg-quick " + option + " " + WIREGUARDPATH + config;
    std::system(command.c_str());
    return;
}
