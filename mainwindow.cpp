#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->registerBox->setVisible(false);
    ui->pushButton_2->deleteLater();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString currentPassword = this->ui->lineEdit->text();
    QString currentUserName = this->ui->lineEdit_2->text();

    QString user = "Mauro";
    QString userPassword = "12345";

    if (userPassword == currentPassword && user == currentUserName)
    {
        this->ui->registerBox->setVisible(true);
        this->ui->pushButton->setText("Registrar Productos");
        this->ui->label_3->setText("Bienvenido");
        this->ui->pushButton->hide();
        this->ui->lineEdit->deleteLater();
        this->ui->lineEdit_2->deleteLater();
        this->ui->label->deleteLater();
        this->ui->label_2->deleteLater();
        this->ui->label->deleteLater();
    }
}



void MainWindow::on_pushButton_3_clicked()
{
    this->ui->label_7->setText("Producto añadido !");
    this->root->insert(this->root, this->ui->lineEdit_3->text().toInt());
    this->Archivo.open("tree.txt", ios::in | ios::app);
    if (this->Archivo.is_open())
    {
        this->Archivo << "\n"
                      << endl;
        this->Archivo << "------------------------------------" << endl;
        this->Archivo.close();
    }

    string id = this->ui->lineEdit_3->text().toStdString();
    string Product = this->ui->lineEdit_4->text().toStdString();
    string detail = this->ui->lineEdit_5->text().toStdString();

    this->Archivo.open("Database.csv", ios::in | ios::app);
    if (this->Archivo.is_open())
    {
        this->Archivo << id << "," << Product << "," << detail << endl;
        this->Archivo.close();
    }

    this->root->traverse();
    this->ui->lineEdit_3->setText("");
    this->ui->lineEdit_4->setText("");
    this->ui->lineEdit_5->setText("");
}

void MainWindow::on_pushButton_4_clicked()
{
#ifdef _WIN32
    system("notepad.exe Database.csv");
#elif defined __unix__
    system("cat Database.csv");
#endif
}

void MainWindow::on_pushButton_5_clicked()
{
#ifdef _WIN32
    system("notepad.exe tree.txt");
#elif defined __unix__
    system("cat tree.txt");
#endif
}

void MainWindow::on_pushButton_2_clicked()
{

}

