#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_pushButtonExit_clicked();

    void on_pushButtonTask3_clicked();

    void on_pushButtonTask1_clicked();

    void on_pushButtonTask2_clicked();

    void on_pushButtonTask4_clicked();

public slots:

    void solution(QString text);

private:
    Ui::MainWindow *ui;

signals:

    void Task1();

    void Task2();

    void Task3();

    void Task4();
};

#endif
