#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pCalculator(new calculator())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pCalculator;
}

void MainWindow::append(char ch)
{
    inputText.append(ch);
    this->ui->editText->setText(inputText);
}

void MainWindow::on_zero_clicked()
{
    this->append('0');
}

void MainWindow::on_one_clicked()
{
    this->append('1');
}


void MainWindow::on_dot_clicked()
{
    this->append('.');
}


void MainWindow::on_two_clicked()
{
    this->append('2');
}

void MainWindow::on_three_clicked()
{
    this->append('3');
}

void MainWindow::on_four_clicked()
{
    this->append('4');
}

void MainWindow::on_five_clicked()
{
    this->append('5');
}

void MainWindow::on_six_clicked()
{
    this->append('6');
}

void MainWindow::on_seven_clicked()
{
    this->append('7');
}

void MainWindow::on_eight_clicked()
{
    this->append('8');
}

void MainWindow::on_nine_clicked()
{
    this->append('9');
}

void MainWindow::on_division_clicked()
{
    this->append('/');
}

void MainWindow::on_multiplication_clicked()
{
    this->append('*');
}

void MainWindow::on_substraction_clicked()
{
    this->append('-');
}

void MainWindow::on_plus_clicked()
{
    this->append('+');
}

void MainWindow::on_equal_clicked()
{
    std::string str = "";
    for(auto it = inputText.begin(); it != inputText.end(); it++){
        str = str + ((char)it->unicode());
    }
    printf("real text %s\n", str.c_str());
    double ret = pCalculator->calculate(inputText);
    inputText = QString::number(ret);
    validateText();
}

void MainWindow::validateText()
{
    this->ui->editText->setText(inputText);
}
