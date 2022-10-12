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

    selectionModel = m_listView->selectionModel();

    setLayout(new QVBoxLayout);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_lineEdit);
    horizontalLayout->addWidget(m_addButton);
    horizontalLayout->addWidget(m_deleteButton);

    layout()->addWidget(m_listView);
    layout()->addItem(horizontalLayout);

    connect(m_addButton, SIGNAL(clicked(bool)), this, SLOT(insertValueFromLineEdit()));
    connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(findSelectionIndex()));
    connect(m_deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteSelectedItem()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::insertValueFromLineEdit()
{
    if (m_lineEdit->text() != "")
    {
        m_model->addValue(m_lineEdit->text());
    }
}

void MainWindow::findSelectionIndex()
{
    if (!selectionModel->selectedIndexes().empty()) {
        index = selectionModel->selectedIndexes().first();
        m_model->getSelectedIndex(index.row());
    } else {
        index = QModelIndex();
    }

}

void MainWindow::deleteSelectedItem()
{
    if (index != QModelIndex())
    {
        selectionModel->clearSelection();
        m_model->deleteValue();

    }
}

