#ifndef WGACTION_H
#define WGACTION_H

#include "qaction.h"
#include "qwidget.h"
#include "qobjectdefs.h"

class wgAction : public QAction {

    Q_OBJECT

public:
    template<typename...Args> wgAction(QString configuration, Args... args);

signals:
    QString triggered();

private:
    QString config;

};
#endif //WGACTION_H
