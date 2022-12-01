#ifndef STANDARDIZATION_WINDOW_H
#define STANDARDIZATION_WINDOW_H

#include <QWidget>

namespace Ui {
class standardization_window;
}

class standardization_window : public QWidget
{
    Q_OBJECT

public:
    explicit standardization_window(QWidget *parent = nullptr);
    ~standardization_window();
    Ui::standardization_window *ui;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_first_clicked();

private:
    //Ui::standardization_window *ui;
};

#endif // STANDARDIZATION_WINDOW_H
