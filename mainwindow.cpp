#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}



void MainWindow::on_pushButtonTask1_clicked()
{
    emit Task1();
}


void MainWindow::on_pushButtonTask2_clicked()
{
    emit Task2();
}


void MainWindow::on_pushButtonTask3_clicked()
{
    emit Task3();
}

void MainWindow::solution(QString text)
{
    ui->label->setText(text);
}

void MainWindow::on_pushButtonTask4_clicked()
{
    emit Task4();
}

