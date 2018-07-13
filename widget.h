#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class MyProgressBar;
class MyDialog;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void updateProgressBar();

private:
    QTimer* timer;
    MyProgressBar *progressBar;
    Ui::Widget *ui;
    MyDialog *myDialog;
};

#endif // WIDGET_H
