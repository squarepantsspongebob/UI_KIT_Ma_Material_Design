#include "mmodel_table.h"
#include "mmodel.h"
#include <QBrush>

ThreeDTableModel::ThreeDTableModel(QObject *parent)
    :QAbstractTableModel(parent)
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

void ThreeDTableModel::addThreeD(const ThreeD &threeD)
{
    beginInsertRows (QModelIndex(), rowCount (), rowCount ());
    m_threeD << threeD;
    endInsertRows ();
}

int ThreeDTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_threeD.size ();
}

int ThreeDTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

QVariant ThreeDTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid ())
        return QVariant();
    if(index.row ()<0 || index.row () >= m_threeD.size ())
        return QVariant();
    const ThreeD &threeD = m_threeD[index.row ()];
    switch (role) {
    case Qt::DisplayRole:
        return QString("SSS");
        break;
    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
        break;
//    case Qt::BackgroundRole:
//        return QBrush("#e5e5e5");
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

QVariant ThreeDTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal){
        switch(section){
        case 0: return tr("Name");
        case 1: return tr("Color");
        case 2: return tr("Visible");
        case 3: return tr("Opacity");
        case 4: return tr("2DVisible");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags ThreeDTableModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::ItemIsEnabled;
    if (index.column() == colNumberWithCheckBox)
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEditable;
    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

bool ThreeDTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if ( index.isValid () && role == Qt::EditRole){
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
            //        case Fill2DRole:
            //            m_threeD[index.row()].setFill2D (value.toBool ());
            //            emit dataChanged (index, index);
            //            break;
        default:
            return false;
        }
    }
    return false;
}

bool ThreeDTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row+count-1);

    //    for (int row=0; row < rows; row++) {
    //        QPair<QString, QString> pair(" ", " ");
    //        listOfPairs.insert(position, pair);
    //    }

    endInsertRows();
    return true;
}

bool ThreeDTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row+count-1);

//    for (int row=0; row < rows; ++row) {
//        m_threeD.removeAt (position);
//    }

    endRemoveRows();
    return true;

}

QHash<int, QByteArray> ThreeDTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[Color3DRole] = "color3D";
    roles[Visible3DRole] = "visible3D";
    roles[Opacity3DRole] = "opacity3D";
    roles[VisibleContour2DRole] = "visibleContour2D";
    roles[Fill2DRole] = "fill2D";
    return roles;
}

