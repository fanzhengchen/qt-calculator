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
    printf("appending %c\n", ch);
    this->ui->textEdit->moveCursor(QTextCursor::End);
    this->ui->textEdit->insertPlainText(QString(ch));
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
    const QString& text = this->ui->textEdit->toPlainText();
    printf("real text %s\n", text.toStdString().c_str());
    double ret = 0;
//    pCalculator->calculate(text);
    QString res = QString::number(ret);
    this->ui->textEdit->setText(res);
    validateText();
}

void MainWindow::validateText()
{

}

void MainWindow::on_clear_clicked()
{
    this->ui->textEdit->clear();
}
