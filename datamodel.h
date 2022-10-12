#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractItemModel>
#include <QObject>

class DataModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit DataModel(QObject *parent);


};

#endif // DATAMODEL_H
