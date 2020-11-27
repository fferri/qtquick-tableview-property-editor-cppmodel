#pragma once

#include <QAbstractTableModel>

class PropertiesTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum PropertyType {
        String,
        Integer,
        Boolean
    };
    Q_ENUM(PropertyType)

    struct Property {
        QString name;
        QVariant value;
        PropertyType type;
    };

    enum CustomRoles {
        NameRole = Qt::UserRole + 1,
        ValueRole,
        TypeRole
    };

    PropertiesTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<Property> m_properties;
};
