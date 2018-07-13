#ifndef MMODEL_H
#define MMODEL_H
#include <QAbstractListModel>
#include <QColor>
#include <QPixmap>

class ThreeD
{
public:
    //姓名，颜色，模型是否显示，透明度，2D轮廓线是否显示
    ThreeD(const QString name, const QColor color3D, const bool visible3D, const float  opacity3D, const bool visibleContour2D, const bool fill2D, QPixmap pixmap);
    //读取数据
    QString name() const;
    QColor color3D() const;
    bool visible3D() const;
    float opacity3D() const;
    bool visibleContour2D() const;
    bool fill2D() const;
    QPixmap getPixmap() const;
    //修改数据
    void setName(const QString name);
    void setColor3D(const QColor color3D);
    void setVisible3D(const bool visible3D);
    void setOpacity3D(const float opacity3D);
    void setVisibleContour2D(const bool visibleContour2D);
    void setFill2D(const bool fill2D);
    void setPixmap(QPixmap pixmap);
    
private:
    QString m_name;
    QColor m_color3D;
    bool m_visible3D;
    float m_opacity3D;
    bool m_visibleContour2D;
    bool m_fill2D;
    QPixmap m_pixmap;
};

class ThreeDModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum ThreeDRoles{
        NameRole = Qt::UserRole+1, Color3DRole, Visible3DRole, Opacity3DRole, VisibleContour2DRole, Fill2DRole, PixMapRole
    };
    Q_ENUM(ThreeDRoles)
    ThreeDModel(QObject *parent=0);
    void addThreeD(const ThreeD &threeD);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE bool setData(const QModelIndex &index, const QVariant &value, int role = NameRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<ThreeD> m_threeD;
    int colNumberWithCheckBox;
};
#endif // MMODEL_H
