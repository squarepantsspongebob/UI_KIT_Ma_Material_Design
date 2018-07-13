#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QProgressBar>


class MyProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    MyProgressBar(QWidget *parent=0, int x=330, int y= 130, int width=330, int height=15);
    void setGeometry(int x, int y, int w, int h);
    void setGeometry(const QRect &rect);
signals:
    void complete();
public slots:
    void setValue(int value);
    void completeAnimation();
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

#endif // MYPROGRESSBAR_H
