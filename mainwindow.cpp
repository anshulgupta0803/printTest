#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QCPDialog.h>

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
    QCPDialog dialog(new QPrinter, Q_NULLPTR);
    if (dialog.exec() != QDialog::Accepted)
        return;
    ui->label->setText(dialog.information());
}
