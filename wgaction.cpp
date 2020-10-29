#include <wgaction.h>

//template<typename... Args> wgAction::wgAction(QString configuration, Args... args) : QWidgetAction(args...) {
    //config = configuration;
//}

//template<typename... Args> wgAction::wgAction(std::string configuration, Args... args) : QWidgetAction(args...) {
    //config = QString::fromStdString(configuration);
//}

//template<typename... Args> wgAction::wgAction(char const *configuration, Args... args) : QWidgetAction(args...) {
    //config = QString::fromStdString(std::string(configuration));
//}

//template<typename... Args> wgAction::wgAction(Args... args) : QWidgetAction(args...) {
    //config = "";
//}

wgAction::wgAction(QString text, QWidget *parent) : QWidgetAction(parent) {
    config = text;
}

//QString wgAction::triggered(bool checked) {
    //QWidgetAction::triggered(checked);
    //return config;
//}

QString wgAction::getConfig() {
    return config;
}

void wgAction::setConfig(QString configuration) {
    config = configuration;
    return;
}
