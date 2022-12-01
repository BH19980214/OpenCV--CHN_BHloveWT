#include "choose_number.h"
#include "ui_choose_number.h"

choose_number::choose_number(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choose_number)
{
    ui->setupUi(this);
}

choose_number::~choose_number()
{
    delete ui;
}
