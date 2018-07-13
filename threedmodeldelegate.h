#ifndef THREEDMODELDELEGATE_H
#define THREEDMODELDELEGATE_H
#include <QItemDelegate>
#include <QTableView>

class ThreeDModel;

class ThreeDModelDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ThreeDModelDelegate(QObject *parent=0);
    ~ThreeDModelDelegate();

//    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class ThreeDModelListView: public QTableView
{
    Q_OBJECT
public:
    ThreeDModelListView(QWidget *parent=0);
    ~ThreeDModelListView();
    ThreeDModelDelegate *delegate;
public slots:
private:
    ThreeDModel *model;
};

#endif // THREEDMODELDELEGATE_H
