#include "threedmodeldelegate.h"
#include "Model/mmodel.h"
#include <QApplication>
#include <QPainter>


ThreeDModelDelegate::ThreeDModelDelegate(QObject *parent)
    :QItemDelegate(parent)
{   
}

ThreeDModelDelegate::~ThreeDModelDelegate ()
{
}

//void ThreeDModelDelegate::paint (QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    painter->save();
//    painter->setRenderHint (QPainter::Antialiasing);
//    /// Draw Background Rounded Rectangle
//    if(option.state & QStyle::State_Selected)
//    {
//        painter->setPen(QColor("#f3d285"));
//    }
//    else{
//        painter->setPen (QColor("#121212"));
//    }
//    painter->setBrush(QBrush(QColor("#121212")));
//    QRect rec=option.rect;
//    painter->drawRoundedRect (rec,5,5);
//    painter->drawPixmap (option.rect.x ()+13, option.rect.y ()+3, 50, 62, index.data(ThreeDModel::PixMapRole).value<QPixmap>().scaled (50, 62));
//    /// Paint Name Label
//    QFont font("Microsoft YaHei", 7);
//    painter->setFont (font);
//    painter->setPen (QColor("#f1f2f3"));
//    QString modelNameText = index.data(ThreeDModel::NameRole).toString ();

//    QRect modelNameRect(option.rect.x ()+2, option.rect.y ()+65, 75, 13);
//    painter->drawText (modelNameRect, Qt::AlignCenter, modelNameText );
//    //
////    QStyleOptionButton check_box_style_option;
////    check_box_style_option.state |= QStyle::State_Enabled;
////    if(true)
////    {
////        check_box_style_option.state |= QStyle::State_On;
////    }
////    else
////    {
////        check_box_style_option.state |= QStyle::State_Off;
////    }
////    check_box_style_option.rect = QRect( option.rect.x()+10,option.rect.y()+14,100,30);
////    QApplication::style()->drawControl(QStyle::CE_CheckBox,&check_box_style_option,painter);
//    painter->restore ();
//}

QSize ThreeDModelDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option); Q_UNUSED(index);
    return QSize(80, 80);
}

//------------------------------------------------------
ThreeDModelListView::ThreeDModelListView(QWidget *parent)
    :QTableView(parent)
{
    delegate = new ThreeDModelDelegate(this);
    model = new ThreeDModel();
    this->setObjectName ("ThreeDModelListView");
    this->setModel (model);
//    this->setItemDelegate (delegate);
    this->setCurrentIndex (model->index (0));
//    this->setHorizontalHeader(QStringList()<< tr("Name") << tr("Color"));
    ///View Set
    this->setFrameShape(QFrame::NoFrame);
    //    this->setGridSize (QSize(80, 80));   //This will ignore spacing set!!!
//    this->setSpacing (6);
    this->setContentsMargins (1,1,10,10);
    this->setDragEnabled (false);
    this->
    /// Update
    connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(repaint())); //Very ImportantImportant
    connect(this, SIGNAL(pressed(QModelIndex)), this, SLOT(repaint())); //Very
}

ThreeDModelListView::~ThreeDModelListView()
{

}

