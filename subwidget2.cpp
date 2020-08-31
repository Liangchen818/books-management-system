#include "subwidget2.h"
#include "ui_subwidget2.h"
#include <QString>
#include <QDataStream>
#include <QFile>
#include "user.h"
#include <QMessageBox>
QFile file_student("../file_student.txt");
int num2=0;
subwidget2::subwidget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget2)
{
    ui->setupUi(this);
    standItemModel1=new QStandardItemModel();
    standItemModel1->setHorizontalHeaderLabels(QStringList()<<"学号"<<"名称"<<"性别"<<"年龄"<<"类别"<<"所属学院"<<"入学时间"<<"毕业时间");
    ui->student->setModel(standItemModel1);
   read();
}

subwidget2::~subwidget2()
{
    delete ui;
}

void subwidget2::on_pushButton_clicked()
{
    QString code=ui->lineEdit->text();//QString sex,age,type,college,rutime,bitime
    QString name=ui->lineEdit_2->text();
    QString sex=ui->lineEdit_3->text();
    QString age=ui->lineEdit_4->text();
    QString type=ui->lineEdit_5->text();
    QString college=ui->lineEdit_6->text();
    QString rutime=ui->lineEdit_7->text();
    QString bitime=ui->lineEdit_8->text();
    if(code==""||name==""||sex==""||age==""||type==""||college==""||rutime==""||bitime==""){
        QMessageBox::critical(NULL,"失败","输入不能为空");
        return;
    }
    Student b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),
         ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->lineEdit_8->text());
  students.push_back(b);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  ui->lineEdit_4->clear();
  ui->lineEdit_5->clear();
  ui->lineEdit_6->clear();
  ui->lineEdit_7->clear();
  ui->lineEdit_8->clear();
  QMessageBox::about(NULL,"成功","添加成功");
//  write();
}

void subwidget2::on_pushButton_2_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","学号或名称不能为空");
        return;
    }

 //   else {
          for(p=students.begin();p!=students.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  students.erase(p);
                  QMessageBox::about(NULL,"成功","删除成功");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
            //  else {
                  QMessageBox::critical(NULL,"失败","没有该学生");
             //     return;
             // }
              /*else {
                  QMessageBox::critical(NULL,"失败","没有该图书");
          }*/
          }
        //QMessageBox::about(NULL,"成功","删除成功");
 //   }
       //   write();
}

void subwidget2::on_pushButton_3_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","学号或名称不能为空");
         return;
    }

  //  else {
          for(p=students.begin();p!=students.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  students.erase(p);
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
             }
              }

                  QMessageBox::about(NULL,"提示","请输入修改后的所有信息");
                  QString code1=ui->lineEdit->text();//QString sex,age,type,college,rutime,bitime
                  QString name1=ui->lineEdit_2->text();
                  QString sex=ui->lineEdit_3->text();
                  QString age=ui->lineEdit_4->text();
                  QString type=ui->lineEdit_5->text();
                  QString college=ui->lineEdit_6->text();
                  QString rutime=ui->lineEdit_7->text();
                  QString bitime=ui->lineEdit_8->text();
                  if(code1==""||name1==""||sex==""||age==""||type==""||college==""||rutime==""||bitime==""){
                      QMessageBox::critical(NULL,"失败","输入不能为空");
                      return;
                  }
                  Student b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),
                       ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->lineEdit_8->text());
                  students.push_back(b);
                 QMessageBox::about(NULL,"成功","修改成功");
                 ui->lineEdit->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();
                 ui->lineEdit_4->clear();
                 ui->lineEdit_5->clear();
                 ui->lineEdit_6->clear();
                 ui->lineEdit_7->clear();
                 ui->lineEdit_8->clear();

      //   write();
       //QMessageBox::about(NULL,"成功","修改成功");
   // }
}

void subwidget2::on_pushButton_4_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","学号或名称不能为空");
         return;
    }
  //  else {
          for(p=students.begin();p!=students.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  QString code1=p->getnumber();
                  QString name1=p->getname();
                  QString sex=p->Getsex();
                  QString age=p->Getage();
                  QString type=p->Gettype();
                  QString college=p->Getcollege();
                  QString rutime=p->Getrutime();
                  QString bitime=p->Getbitime();
                  standItemModel1->setItem(0,0,new QStandardItem(code1));
                  standItemModel1->setItem(0,1,new QStandardItem(name1));
                  standItemModel1->setItem(0,2,new QStandardItem(sex));
                  standItemModel1->setItem(0,3,new QStandardItem(age));
                  standItemModel1->setItem(0,4,new QStandardItem(type));
                  standItemModel1->setItem(0,5,new QStandardItem(college));
                  standItemModel1->setItem(0,6,new QStandardItem(rutime));
                  standItemModel1->setItem(0,7,new QStandardItem(bitime));
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
             /* else {
                  QMessageBox::critical(NULL,"失败","没有该书籍");
                  return;*/
            //  QMessageBox::critical(NULL,"失败","没有该书籍");
              }
          QMessageBox::critical(NULL,"失败","没有该学生");
       //   }
      //   write();
}

void subwidget2::on_pushButton_5_clicked()
{
    bool ok=file_student.open(QIODevice::WriteOnly);
    if(true==ok)
    {
      //  fileClear();
        Student tmp;
        QDataStream stream(&file_student);
        QVector<Student>::iterator it;
        for(it=students.begin();it!=students.end();it++)
        {
           tmp=*it;
           stream<<tmp.getnumber()<<tmp.getname()<<tmp.Getsex()<<tmp.Getage()<<tmp.Gettype()<<tmp.Getcollege()<<
                   tmp.Getrutime()<<tmp.Getbitime();

        }
     file_student.close();
     QMessageBox::about(NULL,"成功","保存成功");
    }
}
void subwidget2::read()
{
    bool isok=file_student.open(QIODevice::ReadOnly);
    if(true==isok)
    {
        QDataStream stream(&file_student);
            stream.device()->seek(0);
            QString code,name,sex,age,type,college,rutime,bitime;//编号、书名、作者、所属科目、出版社、出版时间、入库时间、页数、定价
            while(!file_student.atEnd())
            {
               Student tmp1;
               stream>>code>>name>>sex<<age<<type<<college<<rutime<<bitime;
               tmp1.setnumber(code);
               tmp1.setname(name);
               tmp1.Setsex(sex);
               tmp1.Setage(age);
               tmp1.Settype(type);
               tmp1.Setcollege(college);
               tmp1.Setrutime(rutime);
               tmp1.Setbitime(bitime);
               students.insert(num2,tmp1);
               num2++;

            }
        }
        file_student.close();
}
