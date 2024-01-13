#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AddRoot("hello", "world");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm =new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);
    itm->setText(1,Description);
    //ui->treeWidget->addTopLevelItem(itm);

    AddChild(itm, "one", "hello");
    AddChild(itm, "two", "world");
}
void MainWindow::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *itm =new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);
    itm->setText(1,Description);
    parent->addChild(itm);

    AddChild(itm, "one", "hello");
    AddChild(itm, "two", "world");
}
