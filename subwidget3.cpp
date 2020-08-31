#include "subwidget3.h"
#include "ui_subwidget3.h"
#include <QString>
#include <QDataStream>
#include <QFile>
#include "user.h"
#include <QMessageBox>
QFile file_teacher("../file_teacher.txt");
int num3=0;
subwidget3::subwidget3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget3)
{
    ui->setupUi(this);
    standItemModel1=new QStandardItemModel();
    standItemModel1->setHorizontalHeaderLabels(QStringList()<<"工号"<<"名称"<<"性别"<<"年龄"<<"所属学院"<<"入职时间");
    ui->teacher->setModel(standItemModel1);
   read();
}

subwidget3::~subwidget3()
{
    delete ui;
}

void subwidget3::on_pushButton_clicked()
{
    QString code=ui->lineEdit->text();//sex1,age1,college1,rutime1;//工号、名称、性别、年龄、所属学院、入职时间
    QString name=ui->lineEdit_2->text();
    QString sex1=ui->lineEdit_3->text();
    QString age1=ui->lineEdit_4->text();
    QString college1=ui->lineEdit_5->text();
    QString rutime1=ui->lineEdit_6->text();
    if(code==""||name==""||sex1==""||age1==""||college1==""||rutime1==""){
        QMessageBox::critical(NULL,"失败","输入不能为空");
        return;
    }
    Teacher b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),
         ui->lineEdit_6->text());
  teachers.push_back(b);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  ui->lineEdit_4->clear();
  ui->lineEdit_5->clear();
  ui->lineEdit_6->clear();
  QMessageBox::about(NULL,"成功","添加成功");
//  write();
}

void subwidget3::on_pushButton_2_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","工号或名称不能为空");
        return;
    }

 //   else {
          for(p=teachers.begin();p!=teachers.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  teachers.erase(p);
                  QMessageBox::about(NULL,"成功","删除成功");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
            //  else {
                  QMessageBox::critical(NULL,"失败","没有该教工");
             //     return;
             // }
              /*else {
                  QMessageBox::critical(NULL,"失败","没有该教工");
          }*/
          }
        //QMessageBox::about(NULL,"成功","删除成功");
 //   }
       //   write();
}

void subwidget3::on_pushButton_3_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","工号或名称不能为空");
         return;
    }

  //  else {
          for(p=teachers.begin();p!=teachers.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  teachers.erase(p);
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
             }
              }

                  QMessageBox::about(NULL,"提示","请输入修改后的所有信息");
                  QString code1=ui->lineEdit->text();//sex1,age1,college1,rutime1;//工号、名称、性别、年龄、所属学院、入职时间
                  QString name1=ui->lineEdit_2->text();
                  QString sex1=ui->lineEdit_3->text();
                  QString age1=ui->lineEdit_4->text();
                  QString college1=ui->lineEdit_5->text();
                  QString rutime1=ui->lineEdit_6->text();
                  if(code1==""||name1==""||sex1==""||age1==""||college1==""||rutime1==""){
                      QMessageBox::critical(NULL,"失败","输入不能为空");
                      return;
                  }
                  Teacher b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),
                       ui->lineEdit_6->text());
                teachers.push_back(b);
                 QMessageBox::about(NULL,"成功","修改成功");
                 ui->lineEdit->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();
                 ui->lineEdit_4->clear();
                 ui->lineEdit_5->clear();
                 ui->lineEdit_6->clear();

      //   write();
       //QMessageBox::about(NULL,"成功","修改成功");
   // }
}

void subwidget3::on_pushButton_4_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","工号或名称不能为空");
         return;
    }
  //  else {
          for(p=teachers.begin();p!=teachers.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  QString code1=p->getnumber();//sex1,age1,college1,rutime1
                  QString name1=p->getname();
                  QString sex1=p->Getsex1();
                  QString age1=p->Getage1();
                  QString college1=p->Getcollege1();
                  QString rutime1=p->Getrutime1();
                  standItemModel1->setItem(0,0,new QStandardItem(code1));
                  standItemModel1->setItem(0,1,new QStandardItem(name1));
                  standItemModel1->setItem(0,2,new QStandardItem(sex1));
                  standItemModel1->setItem(0,3,new QStandardItem(age1));
                  standItemModel1->setItem(0,4,new QStandardItem(college1));
                  standItemModel1->setItem(0,5,new QStandardItem(rutime1));
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
             /* else {
                  QMessageBox::critical(NULL,"失败","没有该书籍");
                  return;*/
            //  QMessageBox::critical(NULL,"失败","没有该书籍");
              }
          QMessageBox::critical(NULL,"失败","没有该教工");
       //   }
      //   write();
}

void subwidget3::on_pushButton_5_clicked()
{
    bool ok=file_teacher.open(QIODevice::WriteOnly);
    if(true==ok)
    {
      //  fileClear();
        Teacher tmp;
        QDataStream stream(&file_teacher);
        QVector<Teacher>::iterator it;
        for(it=teachers.begin();it!=teachers.end();it++)
        {
           tmp=*it;
           stream<<tmp.getnumber()<<tmp.getname()<<tmp.Getsex1()<<tmp.Getage1()<<tmp.Getcollege1()<<tmp.Getrutime1();

        }
     file_teacher.close();
     QMessageBox::about(NULL,"成功","保存成功");
    }
}
void subwidget3::read()
{
    bool isok=file_teacher.open(QIODevice::ReadOnly);
    if(true==isok)
    {
        QDataStream stream(&file_teacher);
            stream.device()->seek(0);
            QString code,name,sex1,age1,college1,rutime1;//工号、名称、性别、年龄、所属学院、入职时间
            while(!file_teacher.atEnd())
            {
               Teacher tmp1;
               stream>>code>>name>>sex1>>age1>>college1>>rutime1;//工号、名称、性别、年龄、所属学院、入职时间;
               tmp1.setnumber(code);
               tmp1.setname(name);
               tmp1.Setsex1(sex1);
               tmp1.Setage1(age1);
               tmp1.Setcollege1(college1);
               tmp1.Setrutime1(rutime1);
               teachers.insert(num3,tmp1);
               num3++;

            }
        }
        file_teacher.close();
}
