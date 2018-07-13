#ifndef MMODEL_TABLE_H
#define MMODEL_TABLE_H
#include <QAbstractTableModel>
class ThreeD;

class ThreeDTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ThreeDTableModel(QObject *parent = 0);
    enum ThreeDRoles{
        NameRole = Qt::UserRole+1, Color3DRole, Visible3DRole, Opacity3DRole, VisibleContour2DRole, Fill2DRole, PixMapRole
    };
    Q_ENUM(ThreeDRoles)
    void addThreeD(const ThreeD &threeD);
    int rowCount (const QModelIndex &parent=QModelIndex()) const;
    int columnCount (const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData (int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags (const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<ThreeD> m_threeD;
    int colNumberWithCheckBox;
};

#endif // MMODEL_TABLE_H
