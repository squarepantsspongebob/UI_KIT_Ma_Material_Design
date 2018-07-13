#include "myprogressbar.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QGraphicsDropShadowEffect>


MyProgressBar::MyProgressBar(QWidget *parent, int x, int y, int width, int height):QProgressBar(parent), m_width(width), m_height(height), m_x(x), m_y(y)
{

    this->setRange (0, 100);
    this->setGeometry (x,y,width,height);
    // Animation when first create the object
//    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
//    animation->setDuration (500);
//    animation->setStartValue (QRect(m_x,m_y+m_height, m_width,0));
//    animation->setEndValue (QRect(m_x, m_y, m_width,m_height));
//    animation->start ();
    // Shadow effect
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(2,2);
    effect->setBlurRadius (4);
    this->setGraphicsEffect(effect);
}

void MyProgressBar::setGeometry(int x, int y, int w, int h)
{
    m_x = x;
    m_y = y;
    m_width = w;
    m_height = h;
    QProgressBar::setGeometry (x,y,w,h);
}

void MyProgressBar::setGeometry(const QRect &rect)
{
    m_x = rect.x ();
    m_y = rect.y ();
    m_width = rect.width ();
    m_height = rect.height ();
    QProgressBar::setGeometry (rect);
}


void MyProgressBar::setValue (int value)
{
    if (value == 0)
    {
        // There will be two condition: 1.first create the object, the progressbar is visible
        //   2. the progress bar is invisible
        if(this->height() == 0)   // 1. invisible: need an animation to make the progressbar visible
        {
            QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
            animation->setDuration (100);
//            animation->setEasingCurve (QEasingCurve::InCubic);
            animation->setStartValue (QRect(m_x,m_y+m_height, m_width,0));
            animation->setEndValue (QRect(m_x,m_y, m_width,m_height));
            animation->start ();
        }
        QProgressBar::setValue (value);
    }
    else if(value == 100)
    {
        // First set the value to the maximum value
        QProgressBar::setValue (value);
        // Then Start the Animation
        QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration (200);
        animation->setEasingCurve (QEasingCurve::InCubic);
        animation->setStartValue (QRect(m_x,m_y, m_width,m_height));
        animation->setEndValue (QRect(m_x,m_y+m_height, m_width,0));
        animation->start ();
        // After Animation, Set the value to -1
        connect(animation, SIGNAL(finished()), this, SLOT(reset()));
        connect(animation, SIGNAL(finished()), this, SLOT(completeAnimation()));
    }
    else{
        QProgressBar::setValue (value);
    }
}

void MyProgressBar::completeAnimation()
{
    QProgressBar::setValue (-1);
}
