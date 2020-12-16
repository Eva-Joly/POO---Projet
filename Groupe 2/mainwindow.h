#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_number0_clicked();

    void on_number1_clicked();

    void on_number2_clicked();

    void on_number3_clicked();

    void on_number4_clicked();

    void on_number5_clicked();

    void on_number6_clicked();

    void on_number7_clicked();

    void on_number8_clicked();

    void on_number9_clicked();


    void on_clearBouton_clicked();

    void on_virguleBouton_clicked();

    void on_diviserBouton_clicked();

    void on_multiplierBouton_clicked();

    void on_soustraireBouton_clicked();

    void on_additionnerBouton_clicked();

    void on_calculBouton_clicked();

    void on_validerBouton_clicked();

private:
    Ui::MainWindow *ui;
    float premierNombre;
};
#endif // MAINWINDOW_H
