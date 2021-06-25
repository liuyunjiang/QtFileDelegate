#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "filedelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel* model = new QStandardItemModel(3, 2, this);

    ui->tableView->setModel(model);

    CFileDelegate* fd = new CFileDelegate(this);
    ui->tableView->setItemDelegateForColumn(1, fd);
}

MainWindow::~MainWindow()
{
    delete ui;
}

