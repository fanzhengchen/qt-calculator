#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_zero_clicked();

    void on_dot_clicked();

    void on_one_clicked();


    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_division_clicked();

    void on_multiplication_clicked();

    void on_substraction_clicked();

    void on_plus_clicked();

private:
    Ui::MainWindow *ui;
    QString inputText;

    void append(char ch);
};

#endif // MAINWINDOW_H
