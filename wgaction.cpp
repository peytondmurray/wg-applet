#include <wgaction.h>

wgAction::wgAction(QString text, QWidget *parent) : QWidgetAction(parent) {
    setText(text);
}

wgAction::wgAction(QString text, QString conf, QWidget *parent) : QWidgetAction(parent) {
    setText(text);
    config = conf;
}

QString wgAction::triggered(bool checked) {
    //QWidgetAction::triggered(checked);
    //return config;
    emit action_triggered(getConfig())
    return;
}

QString wgAction::getConfig() {
    return config;
}

void wgAction::setConfig(QString configuration) {
    config = configuration;
    return;
}
