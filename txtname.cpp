#include "txtname.h"
#include "ui_txtname.h"

TxtName::TxtName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TxtName)
{
    ui->setupUi(this);
}

TxtName::~TxtName()
{
    delete ui;
}
