#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QModelIndex>

#include "datamodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

    QListView *m_listView;
    QLineEdit *m_lineEdit;
    QPushButton *m_addButton;
    QPushButton *m_deleteButton;

    DataModel *m_model;

    QItemSelectionModel *selectionModel;
    QModelIndexList indexes;
    QModelIndex index;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void insertValueFromLineEdit();
    void findSelectionIndex();
    void deleteSelectedItem();


};
#endif // WIDGET_H
