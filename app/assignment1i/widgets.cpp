//***************************************
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QPushButton>
#include <QWidget>

#include "window.h"

MyWidget::MyWidget(QWidget *parent)
: QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Helvetica", 12));

    QSlider *volslider = new QSlider(Qt::Horizontal);
    volslider->setRange(0, 99);
    volslider->setValue(0);
    QLCDNumber *vollcd = new QLCDNumber(2);
    vollcd->setSegmentStyle(QLCDNumber::Filled);

    QDial *fmdial = new QDial;
    fmdial->setNotchesVisible(true);
    fmdial->setMinimum(0);
    fmdial->setMaximum(100);
    QLCDNumber *fmlcd = new QLCDNumber(3);

    QSlider *amslider = new QSlider(Qt::Vertical);
    amslider->setRange(0, 10);
    amslider->setValue(5);
    QLCDNumber *amlcd = new QLCDNumber(3);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(volslider, SIGNAL(valueChanged(int)),
    vollcd, SLOT(display(int)));
    connect(fmdial, SIGNAL(valueChanged(int)),
    fmlcd, SLOT(display(int)));
    connect(amslider, SIGNAL(valueChanged(int)),
    amlcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(vollcd);
    layout->addWidget(volslider);
    layout->addWidget(fmdial);
    layout->addWidget(fmlcd);
    layout->addWidget(amslider);
    layout->addWidget(amlcd);
    setLayout(layout);
}
