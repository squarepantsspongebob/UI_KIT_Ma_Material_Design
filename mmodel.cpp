#include "mmodel.h"
#include <QModelIndex>
#include <QDebug>
#include <QTime>
#include <QPixmap>

//ThreeD
//Constructor
ThreeD::ThreeD(const QString name, const QColor color3D, const bool visible3D, const float opacity3D, const bool visibleContour2D, const bool fill2D, QPixmap pixmap)
    :m_name(name), m_color3D(color3D), m_visible3D(visible3D), m_opacity3D(opacity3D), m_visibleContour2D(visibleContour2D), m_fill2D(fill2D), m_pixmap(pixmap)
{
}  

//Read Function
QString ThreeD::name () const
{
    return m_name;
}

QColor ThreeD::color3D () const
{
    return m_color3D;
}

bool ThreeD::visible3D () const
{
    return m_visible3D;
}

float ThreeD::opacity3D () const
{
    return m_opacity3D;
}

bool ThreeD::visibleContour2D () const
{
    return m_visibleContour2D;
}

bool ThreeD::fill2D () const
{
    return m_fill2D;
}

QPixmap ThreeD::getPixmap() const
{
    return m_pixmap;
}

// Modify Function
void ThreeD::setName (const QString name)
{
    m_name = name;
}
void ThreeD::setColor3D (const QColor color3D)
{
    m_color3D = color3D;
}
void ThreeD::setVisible3D (const bool visible3D)
{
    m_visible3D = visible3D;
}
void ThreeD::setOpacity3D (const float opacity3D)
{
    m_opacity3D = opacity3D;
}
void ThreeD::setVisibleContour2D (const bool visibleContour2D)
{
    m_visibleContour2D = visibleContour2D;
}
void ThreeD::setFill2D (const bool fill2D)
{
    m_fill2D = fill2D;
}

void ThreeD::setPixmap(QPixmap pixmap)
{
    m_pixmap = pixmap;
}

//ThreeDModel
//Constructor
ThreeDModel::ThreeDModel(QObject *parent)
    :QAbstractListModel(parent), colNumberWithCheckBox(0)
{
    addThreeD (ThreeD("Bone", "#9C815F", true, 1, false, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Skin", "#E0E000", true, 1, false, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Mirror", "#E90000", false, 1, false, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Mandible", "#1669B9", true, 0.5, false, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Bone1", "#9C815F", true, 0.5, true, true, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Bone2", "#9C815F", true, 0.5, false, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Bone3", "#9C815F", true, 1, true, false, QPixmap(":/Img/Pic/BONE.png")));
    addThreeD (ThreeD("Bone4", "#9C815F", true, 0.5, false, false, QPixmap(":/Img/Pic/BONE.png")));
}

void ThreeDModel::addThreeD(const ThreeD &threeD)
{
    beginInsertRows (QModelIndex(), rowCount (), rowCount ());
    m_threeD << threeD;
    endInsertRows ();
}

int ThreeDModel::rowCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_threeD.count ();
}

QVariant ThreeDModel::data (const QModelIndex &index, int role) const
{
    if(index.row ()<0 || index.row () >= m_threeD.count ())
        return QVariant();
    const ThreeD &threeD = m_threeD[index.row ()];
    switch (role) {
    case NameRole:
        return threeD.name ();
        break;
    case Color3DRole:
        return threeD.color3D ();
        break;
    case Visible3DRole:
        return threeD.visible3D ();
        break;
    case Opacity3DRole:
        return threeD.opacity3D ();
        break;
    case VisibleContour2DRole:
        return threeD.visibleContour2D ();
        break;
    case Fill2DRole:
        return threeD.fill2D ();
        break;
    case PixMapRole:
        return threeD.getPixmap ();
        break;
    default:
        return QVariant();
        break;
    }
}

//RoleName
QHash<int, QByteArray> ThreeDModel::roleNames () const{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Color3DRole] = "color3D";
    roles[Visible3DRole] = "visible3D";
    roles[Opacity3DRole] = "opacity3D";
    roles[VisibleContour2DRole] = "visibleContour2D";
    roles[Fill2DRole] = "fill2D";
    return roles;
}

//Modify Model Data
bool ThreeDModel::setData (const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid ())
    {
        switch (role) {
        case NameRole:
            m_threeD[index.row()].setName (value.toString ());
            emit dataChanged (index, index);
            break;
        case Color3DRole:
            m_threeD[index.row ()].setColor3D (value.toString ());
            emit dataChanged (index, index);
            break;
        case Visible3DRole:
            m_threeD[index.row ()].setVisible3D (value.toBool ());
            emit dataChanged (index, index);
            break;
        case Opacity3DRole:
            m_threeD[index.row()].setOpacity3D (value.toFloat ());
            emit dataChanged(index, index);
            break;
        case VisibleContour2DRole:
            m_threeD[index.row()].setVisibleContour2D (value.toBool ());
            emit dataChanged (index, index);
            break;
        case Fill2DRole:
            m_threeD[index.row()].setFill2D (value.toBool ());
            emit dataChanged (index, index);
            break;
        default:
            return false;
        }
    }
    return false;
}

Qt::ItemFlags ThreeDModel::flags(const QModelIndex &index) const
{
//    if (!index.isValid())
//        return 0;
//    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
    if
    (!index.isValid())
    return 0;


    if (index.column() == colNumberWithCheckBox)
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;


    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
