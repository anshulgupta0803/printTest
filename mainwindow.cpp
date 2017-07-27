#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cpd = new CPD(new QPrinter, Q_NULLPTR);
    cpd->show();
    ui->label->setText(cpd->information());
}