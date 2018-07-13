#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
class MyButton1;

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    MyDialog(QWidget *parent=0);
signals:
public slots:
private:
    void createUI();
    MyButton1 *okBtn;
    MyButton1 *cancelBtn;
};

#endif // MYDIALOG_H
