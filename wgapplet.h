#ifndef WGAPPLET_H
#define WGAPPLET_H

#include "wgaction.h"
#include "qobjectdefs.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <filesystem>

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
    //void start(wgAction *action);
    //void stop(wgAction *action);
    void start(bool checked);
    //void stop(bool checked);
    void stop(QString checked);

private:
    void createTrayIcon();
    void createActions();
    QMenu * createMenu();
    void refreshActions();

    void createConfigs(std::string path);
    void refreshConfigs(std::string path);

    void setConnection(std::string option, std::string config);

    QList<std::filesystem::path> configs;
    QList<wgAction *> actions;
    QSystemTrayIcon *trayIcon;
    QMenu *menu;
    Ui::wgApplet *ui;
};
#endif // WGAPPLET_H
