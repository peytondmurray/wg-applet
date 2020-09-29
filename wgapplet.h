#ifndef WGAPPLET_H
#define WGAPPLET_H

#include <filesystem>
#include "qaction.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class wgApplet; }
QT_END_NAMESPACE

class wgApplet : public QMainWindow
{
    Q_OBJECT

public:
    wgApplet(QWidget *parent = nullptr);
    ~wgApplet();

private slots:
    void startConnection(QAction *action);

private:
    void createTrayIcon();
    void createActions();
    void refreshActions();

    void createConfigs(std::string path);
    void refreshConfigs(std::string path);

    enum ConnectionCommand {up, down};

    QList<std::filesystem::path> configs;
    QList<QAction *> actions;
    QSystemTrayIcon *trayIcon;
    QMenu *menu;
    Ui::wgApplet *ui;
};
#endif // WGAPPLET_H
