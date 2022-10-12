#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include <QStringList>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT

    QStringList m_data;
    int selectedIndex;

public:
    explicit DataModel(QObject *parent);

    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &index) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

public slots:
    void addValue(const QString &value);
    void deleteValue();
    void getSelectedIndex(const int &row);
};

#endif // DATAMODEL_H
