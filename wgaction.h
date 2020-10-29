#ifndef WGACTION_H
#define WGACTION_H

#include "qaction.h"
#include "qobjectdefs.h"
#include "qwidgetaction.h"

class wgAction : public QWidgetAction {

    Q_OBJECT

public:
    //template<typename...Args> wgAction(Args... args);
    //template<typename...Args> wgAction(QString configuration, Args... args);
    //template<typename...Args> wgAction(char const *configuration, Args... args);
    //template<typename...Args> wgAction(std::string configuration, Args... args);
    wgAction(QString text, QWidget *parent);

    QString getConfig();
    void setConfig(QString configuration);

//signals:
    //QString triggered(bool checked);

private:
    QString config;

};
#endif //WGACTION_H
