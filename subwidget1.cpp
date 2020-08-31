#include "subwidget1.h"
#include "ui_subwidget1.h"
#include "user.h"
#include <QString>
#include <QDataStream>
#include <QFile>
#include <QMessageBox>
QFile file_librarian("../file_librarian.txt");
int num1=0;
subwidget1::subwidget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget1)
{
    ui->setupUi(this);
    standItemModel1=new QStandardItemModel();
    standItemModel1->setHorizontalHeaderLabels(QStringList()<<"工号"<<"名称"<<"岗位");
    ui->librarian->setModel(standItemModel1);
   read();
}

subwidget1::~subwidget1()
{
    delete ui;
}

void subwidget1::on_pushButton_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    QString post=ui->lineEdit_3->text();
    if(code==""||name==""||post==""){
        QMessageBox::critical(NULL,"失败","输入不能为空");
        return;
    }
    Librarian b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
  librarians.push_back(b);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  QMessageBox::about(NULL,"成功","添加成功");
}

void subwidget1::on_pushButton_2_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","工号或名称不能为空");
        return;
    }

          for(p=librarians.begin();p!=librarians.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  librarians.erase(p);
                  QMessageBox::about(NULL,"成功","删除成功");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }

                  QMessageBox::critical(NULL,"失败","没有该管理员");

          }

}

void subwidget1::on_pushButton_3_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","工号或名称不能为空");
         return;
    }

          for(p=librarians.begin();p!=librarians.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  librarians.erase(p);
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
             }
              }

                  QMessageBox::about(NULL,"提示","请输入修改后的所有信息");
                  QString code1=ui->lineEdit->text();
                  QString name1=ui->lineEdit_2->text();
                  QString post1=ui->lineEdit_3->text();
                  if(code1==""||name1==""||post1==""){
                      QMessageBox::critical(NULL,"失败","输入不能为空");
                      return;
                  }
                  Librarian b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
                librarians.push_back(b);
                 QMessageBox::about(NULL,"成功","修改成功");
                 ui->lineEdit->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();

}

void subwidget1::on_pushButton_4_clicked()
{

QString code=ui->lineEdit->text();
QString name=ui->lineEdit_2->text();
if(code==""&&name==""){
    QMessageBox::critical(NULL,"失败","工号或名称不能为空");
     return;
}
      for(p=librarians.begin();p!=librarians.end();p++)
      {
          QString c,n;
          c= p->getnumber();
          n=p->getname();
          if(code==c||name==n)
          {
              QString code1=p->getnumber();
              QString name1=p->getname();
              QString post=p->getpost();
              standItemModel1->setItem(0,0,new QStandardItem(code1));
              standItemModel1->setItem(0,1,new QStandardItem(name1));
              standItemModel1->setItem(0,2,new QStandardItem(post));
              ui->lineEdit->clear();
              ui->lineEdit_2->clear();
              return;
          }

          }
      QMessageBox::critical(NULL,"失败","没有该管理员");
   }

void subwidget1::on_pushButton_5_clicked()
{
    bool ok=file_librarian.open(QIODevice::WriteOnly);
    if(true==ok)
    {
      //  fileClear();
        Librarian tmp;
        QDataStream stream(&file_librarian);
        QVector<Librarian>::iterator it;
        for(it=librarians.begin();it!=librarians.end();it++)
        {
           tmp=*it;
           stream<<tmp.getnumber()<<tmp.getname()<<tmp.getpost();
        }
     file_librarian.close();
     QMessageBox::about(NULL,"成功","保存成功");
    }
}
void subwidget1::read()
{
    bool isok=file_librarian.open(QIODevice::ReadOnly);
    if(true==isok)
    {
        QDataStream stream(&file_librarian);
            stream.device()->seek(0);
            QString code,name,post;
            while(!file_librarian.atEnd())
            {
               Librarian tmp1;
               stream>>code>>name>>post;
               tmp1.setnumber(code);
               tmp1.setname(name);
               tmp1.Setpost(post);
               librarians.insert(num1,tmp1);
               num1++;

            }
        }
        file_librarian.close();
}
