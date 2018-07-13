#ifndef MYBUTTON1_H
#define MYBUTTON1_H

#include <QPushButton>
class QGraphicsDropShadowEffect;

class MyButton1 : public QPushButton
{
    Q_OBJECT
public:
    MyButton1(QWidget *parent=0, bool haveShadow=true);
    void paintEvent (QPaintEvent *e) override;
    void mousePressEvent (QMouseEvent *event) override;
    void setEnabled (bool);
private:
    QGraphicsDropShadowEffect *effect;
    bool m_haveShadow;




};

#endif // MYBUTTON1_H
