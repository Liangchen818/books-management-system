#ifndef SUBWIDGET4_H
#define SUBWIDGET4_H

#include <QWidget>
#include <QStandardItemModel>
#include "user.h"
namespace Ui {
class subwidget4;
}

class subwidget4 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget4(QWidget *parent = nullptr);
    ~subwidget4();
    void write();
    void read();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::subwidget4 *ui;
    QVector<Readclass> readclasses;
    QVector<Readclass>::iterator p;
    QStandardItemModel *standItemModel1;
};

#endif // SUBWIDGET4_H
