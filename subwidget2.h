#ifndef SUBWIDGET2_H
#define SUBWIDGET2_H

#include <QWidget>
#include <QStandardItemModel>
#include "user.h"
namespace Ui {
class subwidget2;
}

class subwidget2 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget2(QWidget *parent = nullptr);
    ~subwidget2();
    void write();
    void read();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::subwidget2 *ui;
    QVector<Student> students;
    QVector<Student>::iterator p;
    QStandardItemModel *standItemModel1;
};

#endif // SUBWIDGET2_H
