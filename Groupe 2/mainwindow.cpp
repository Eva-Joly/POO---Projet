#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "constante.h"
#include "addition.h"
#include "soustraction.h"
#include "division.h"


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


void MainWindow::on_number0_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("0");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("0");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "0");
    }
}

void MainWindow::on_number1_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("1");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("1");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "1");
    }
}

void MainWindow::on_number2_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("2");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("2");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "2");
    }
}


void MainWindow::on_number3_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("3");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("3");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "3");
    }
}

void MainWindow::on_number4_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("4");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("4");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "4");
    }
}

void MainWindow::on_number5_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("5");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("5");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "5");
    }
}

void MainWindow::on_number6_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("6");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("6");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "6");
    }
}

void MainWindow::on_number7_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("7");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("7");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "7");
    }
}

void MainWindow::on_number8_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("8");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("8");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "8");
    }
}

void MainWindow::on_number9_clicked()
{
    if(ui->resultLine->text() == "0")
    {
        ui->resultLine->setText("9");
    }
    else if(ui->resultLine->text() == "0" and not premierNombre)
    {
        ui->resultLine->setText("9");
    }
    else if(ui->resultLine->text() != "0")
    {
        ui->resultLine->setText(ui->resultLine->text() + "9");
    }
}



void MainWindow::on_clearBouton_clicked()
{
    ui->resultLine->setText("0");
    premierNombre = 0;
}

void MainWindow::on_virguleBouton_clicked()
{
    ui->resultLine->setText(ui->resultLine->text() + ".");

}

void MainWindow::on_diviserBouton_clicked()
{

}

void MainWindow::on_multiplierBouton_clicked()
{

}

void MainWindow::on_soustraireBouton_clicked()
{

}

void MainWindow::on_additionnerBouton_clicked()
{

}

void MainWindow::on_calculBouton_clicked()
{

}

void MainWindow::on_validerBouton_clicked()
{

}
