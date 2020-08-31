#ifndef SUBWIDGET5_H
#define SUBWIDGET5_H
#include "records.h"
#include <QWidget>
#include <QStandardItemModel>
namespace Ui {
class subwidget5;
}

class subwidget5 : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget5(QWidget *parent = nullptr);
    ~subwidget5();
    void write();
    void read();
    const QString getCurrentSystemTime();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::subwidget5 *ui;
    QVector<Records> records;
    QVector<Records>::iterator p;
    QStandardItemModel *standItemModel1;
};

#endif // SUBWIDGET5_H
