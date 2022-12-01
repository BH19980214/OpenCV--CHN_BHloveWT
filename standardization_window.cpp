#include "standardization_window.h"
#include "ui_standardization_window.h"

standardization_window::standardization_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::standardization_window)
{
    ui->setupUi(this);
}

standardization_window::~standardization_window()
{
    delete ui;
}

void standardization_window::on_pushButton_clicked()
{
    ui->sw_stan->setCurrentIndex(0);
}

void standardization_window::on_pushButton_2_clicked()
{
     ui->sw_stan->setCurrentIndex(1);
}


void standardization_window::on_pb_first_clicked()
{

}

