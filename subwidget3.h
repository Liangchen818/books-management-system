#ifndef SUBWIDGET3_H
#define SUBWIDGET3_H

#include <QWidget>
#include <QStandardItemModel>
#include "user.h"
namespace Ui {
class subwidget3;
}

class subwidget3 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget3(QWidget *parent = nullptr);
    ~subwidget3();
    void write();
    void read();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::subwidget3 *ui;
    QVector<Teacher> teachers;
    QVector<Teacher>::iterator p;
    QStandardItemModel *standItemModel1;
};

#endif // SUBWIDGET3_H
