#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    m_model = new DataModel(this);
    m_listView = new QListView(this);
    m_listView->setModel(m_model);

    m_lineEdit = new QLineEdit(this);
    m_addButton = new QPushButton("Add", this);
    m_deleteButton = new QPushButton("Delete", this);



    setLayout(new QVBoxLayout);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_lineEdit);
    horizontalLayout->addWidget(m_addButton);
    horizontalLayout->addWidget(m_deleteButton);

    layout()->addWidget(m_listView);
    layout()->addItem(horizontalLayout);

}

MainWindow::~MainWindow()
{

}

