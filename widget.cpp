#include "widget.h"
#include "ui_widget.h"
#include "MyComponent/myprogressbar.h"
#include "MyComponent/mydialog.h"
#include "model/mmodel_table.h"
#include <QDebug>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QTimer>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    this->setWindowFlags (Qt::FramelessWindowHint);
    // Set StyleSheet
    QFile file(":/qrc/default.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString styleSheet = filetext.readAll();
    this->setStyleSheet (styleSheet);
    //
    ui->setupUi(this);
    ui->pushButon_enabled->setObjectName ("pushButton_enabled");
    ui->pushButton_disabled->setObjectName ("pushButton_disabled");
    ui->pushButton_disabled->setEnabled (false);
    ThreeDTableModel *model = new ThreeDTableModel(this);
    ui->tableView->setModel (model);
    ui->tableView->setSelectionBehavior (QAbstractItemView::SelectRows); //when click, select the whole row
    ui->tableView->verticalHeader ()->setSectionHidden (0,true); //Hide the vertical headerview
    ui->tableView->horizontalHeader ()->setMinimumHeight (30);
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset (0,2);
    effect->setBlurRadius (6);
    effect->setColor (QColor("#cccccc"));
    ui->tableView->setGraphicsEffect (effect);

    timer = new QTimer();
    timer->setInterval (10);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateProgressBar()));
    //
    connect(ui->pushButton, SIGNAL(clicked(bool)),timer, SLOT(start()));
    // My Dialog
    myDialog = new MyDialog(this);
    connect(ui->pushButton_open, SIGNAL(clicked(bool)), myDialog, SLOT(open()));
}
///////////////////////////////////
/// \brief Widget::updateProgressBar
///    update the value of the progress bar
///////////////////////////////////
void Widget::updateProgressBar()
{
    int value = ui->progressBar->value ();
    value++;
    ui->progressBar->setValue(value);
    if(value == 100)
        timer->stop ();
}

Widget::~Widget()
{
    delete ui;
}

