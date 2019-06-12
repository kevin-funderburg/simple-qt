#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QGroupBox;

class Window : public QWidget
{
    Q_OBJECT

    public:
        Window(QWidget *parent = 0);

    private:
        QGroupBox *createFirstExclusiveGroup();
        QGroupBox *createSecondExclusiveGroup();
        QGroupBox *createNonExclusiveGroup();
        QGroupBox *createPushButtonGroup();
};


class MyWidget : public QWidget
{
    public:
        MyWidget(QWidget *parent = 0);
};


#endif
