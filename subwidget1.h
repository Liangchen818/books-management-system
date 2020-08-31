#ifndef SUBWIDGET1_H
#define SUBWIDGET1_H
#include "user.h"
#include <QWidget>
#include "user.h"
#include <QStandardItemModel>
namespace Ui {
class subwidget1;
}

class subwidget1 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget1(QWidget *parent = nullptr);
    ~subwidget1();
    void write();
    void read();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::subwidget1 *ui;
    QVector<Librarian> librarians;
    QVector<Librarian>::iterator p;
    QStandardItemModel *standItemModel1;
};

#endif // SUBWIDGET1_H
