#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QFont>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Microsoft YaHei");
    a.setFont (font);
    // Set StyleSheet
//    QFile file(":/qrc/default.qss");
//    file.open(QFile::ReadOnly);
//    QTextStream filetext(&file);
//    QString styleSheet = filetext.readAll();
//    a.setStyleSheet (styleSheet);

    Widget w;
    w.show();

    return a.exec();
}
