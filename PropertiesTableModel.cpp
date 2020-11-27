#include "PropertiesTableModel.h"

PropertiesTableModel::PropertiesTableModel(QObject *parent)
{
    m_properties.append({"String prop", "StringProperty", PropertyType::String});
    m_properties.append({"Int prop", 55, PropertyType::Integer});
    m_properties.append({"Bool prop", true, PropertyType::Boolean});
}

int PropertiesTableModel::rowCount(const QModelIndex &) const
{
    return m_properties.size();
}

int PropertiesTableModel::columnCount(const QModelIndex &) const
{
    return 2;
}

QVariant PropertiesTableModel::data(const QModelIndex &index, int role) const
{
    auto& property = m_properties.at(index.row());
    switch (role) {
        case CustomRoles::NameRole:
            return property.name;
        case CustomRoles::TypeRole:
            if (index.column() > 0)
                return property.type;
            else
                return -1;
        case CustomRoles::ValueRole:
            return property.value;
        default:
            break;
    }

    return QVariant();
}

QHash<int, QByteArray> PropertiesTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ValueRole] = "value";
    roles[TypeRole] = "type";
    return roles;
}
