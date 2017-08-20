#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include <QPainter>
#include <QCPDialog.h>
#include <QPrintDialog>

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
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);

    QCPDialog dialog(printer, Q_NULLPTR);
//    QPrintDialog dialog(printer, Q_NULLPTR);

    dialog.setWindowTitle("Print Document");

    if (dialog.exec() != QDialog::Accepted) {
        ui->label->setText("Print Cancelled");
        return;
    }

    QPainter painter;
    painter.begin(printer);

    QRect rect({100, 100}, QSize{500, 500});
    QString text{"Hello World"};

    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, text);
    painter.drawEllipse(rect);

    painter.end();

    ui->label->setText("Print Successful");

    return;
}
