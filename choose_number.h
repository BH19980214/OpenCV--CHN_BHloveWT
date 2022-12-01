#ifndef CHOOSE_NUMBER_H
#define CHOOSE_NUMBER_H

#include <QWidget>

namespace Ui {
class choose_number;
}

class choose_number : public QWidget
{
    Q_OBJECT

public:
    explicit choose_number(QWidget *parent = nullptr);
    ~choose_number();
    Ui::choose_number *ui;
};

#endif // CHOOSE_NUMBER_H
