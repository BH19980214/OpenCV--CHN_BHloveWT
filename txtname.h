#ifndef TXTNAME_H
#define TXTNAME_H

#include <QWidget>

namespace Ui {
class TxtName;
}

class TxtName : public QWidget
{
    Q_OBJECT

public:
    explicit TxtName(QWidget *parent = nullptr);
    ~TxtName();
    Ui::TxtName *ui;
private:

};

#endif // TXTNAME_H
