#ifndef ACCEVENTS_H
#define ACCEVENTS_H

#include <QWidget>

namespace Ui {
class accEvents;
}

class accEvents : public QWidget
{
    Q_OBJECT

public:
    explicit accEvents(QString events, QWidget *parent = nullptr);
    ~accEvents();

private:
    Ui::accEvents *ui;
};

#endif // ACCEVENTS_H
