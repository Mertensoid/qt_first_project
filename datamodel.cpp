#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QAbstractItemModel{parent}
{

}

QModelIndex DataModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column, (void*)&m_data[row]);
}

QModelIndex DataModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int DataModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_data.at(index.row());
    }
    return QVariant();
}

void DataModel::addValue(const QString &value)
{
    m_data.append(value);
    emit layoutChanged();
}

void DataModel::deleteValue()
{
    printf("here");
    m_data.removeAt(selectedIndex);
    emit layoutChanged();

}

void DataModel::getSelectedIndex(const int &row)
{
    selectedIndex = row;
}
