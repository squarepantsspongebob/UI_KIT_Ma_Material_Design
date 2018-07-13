#include "mydialog.h"
#include "mybutton1.h"
#include <QApplication>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>

MyDialog::MyDialog(QWidget *parent):QDialog(parent)
{
    setWindowFlags (Qt::FramelessWindowHint | Qt::Dialog);
    this->setAttribute (Qt::WA_TranslucentBackground, true);
    setModal (true);
    this->setFixedHeight (parent->height ());
    this->setFixedWidth (parent->width ());
    createUI();
}

void MyDialog::createUI()
{
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setFixedSize (this->size ());
    mainWidget->setObjectName ("mainWidget");

    QWidget *subWidget = new QWidget(mainWidget);
    subWidget->setGeometry(760, 360, 350, 301);
    subWidget->setObjectName("subWidget");
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(subWidget);
    effect->setOffset(0,4);
    effect->setBlurRadius (20);
//    effect->setColor (QColor("#cccccc"));
    subWidget->setGraphicsEffect(effect);

    // Component
    QLabel *label1 = new QLabel(subWidget);
    label1->setObjectName ("label1");
    label1->setText ("Are You Sure to Quit?");
    label1->setGeometry (20,40,311,21);

    QLabel *label2 = new QLabel(subWidget);
    label2->setObjectName ("label2");
    label2->setText ("If you leave the checkout \nyour patient information\nwill not be saved.");
    label2->setGeometry (20,100,251,85);

    okBtn = new MyButton1(subWidget, false);
    okBtn->setText("OK");
    okBtn->setGeometry (230,230,100, 36);
    cancelBtn = new MyButton1(subWidget, false);
    cancelBtn->setText("CANCEL");
    cancelBtn->setGeometry (120, 230, 100, 36);
    //
    connect(okBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}
