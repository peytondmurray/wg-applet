#include <wgaction.h>


template<typename... Args> wgAction::wgAction(QString configuration, Args... args) : QAction(args...) {
    config = configuration;
}

QString wgAction::triggered() {
    return config;
}
