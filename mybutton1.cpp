#include "mybutton1.h"

#include <QGraphicsDropShadowEffect>

MyButton1::MyButton1(QWidget *parent, bool haveShadow):QPushButton(parent),m_haveShadow(haveShadow)
{
    if(m_haveShadow)
    {
        effect = new QGraphicsDropShadowEffect(this);
        effect->setOffset(0,2);
        effect->setBlurRadius (4);
        effect->setColor (QColor("#cccccc"));
        this->setGraphicsEffect(effect);
    }
}

void MyButton1::paintEvent(QPaintEvent *e)
{
    QPushButton::paintEvent(e);
}

void MyButton1::mousePressEvent(QMouseEvent *event)
{
    QPushButton::mousePressEvent (event);
}

void MyButton1::setEnabled(bool enabled)
{
    if (this->isEnabled () == enabled)
        return;
    if (enabled)
        this->setGraphicsEffect (effect);
    else
        this->setGraphicsEffect (NULL);
    QPushButton::setEnabled (enabled);
}
