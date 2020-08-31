#include "subwidget4.h"
#include "ui_subwidget4.h"
#include <QString>
#include <QDataStream>
#include <QFile>
#include "user.h"
#include <QMessageBox>
QFile file_readclass("../file_readclass.txt");
int num4=0;
subwidget4::subwidget4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget4)
{
    ui->setupUi(this);
    standItemModel1=new QStandardItemModel();
    standItemModel1->setHorizontalHeaderLabels(QStringList()<<"编号"<<"名称"<<"借阅时长限制"<<"借阅册数限制"<<"其他说明");
    ui->readclass->setModel(standItemModel1);
   read();
}

subwidget4::~subwidget4()
{
    delete ui;
}

void subwidget4::on_pushButton_clicked()
{
    QString code=ui->lineEdit->text();//读者类别（编号、名称、借阅时长限制、借阅册数限制、其它说明等readtime,readamount,other;
    QString name=ui->lineEdit_2->text();
    QString readtime=ui->lineEdit_3->text();
    QString readamount=ui->lineEdit_4->text();
    QString other=ui->lineEdit_5->text();
    if(code==""||name==""||readtime==""||readamount==""||other==""){
        QMessageBox::critical(NULL,"失败","输入不能为空");
        return;
    }
    Readclass b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text() );
  readclasses.push_back(b);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  ui->lineEdit_4->clear();
  ui->lineEdit_5->clear();
  QMessageBox::about(NULL,"成功","添加成功");
//  write();
}

void subwidget4::on_pushButton_2_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","编号或名称不能为空");
        return;
    }

 //   else {
          for(p=readclasses.begin();p!=readclasses.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  readclasses.erase(p);
                  QMessageBox::about(NULL,"成功","删除成功");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
            //  else {
                  QMessageBox::critical(NULL,"失败","没有该类别");
             //     return;
             // }
              /*else {
                  QMessageBox::critical(NULL,"失败","没有该类别");
          }*/
          }
        //QMessageBox::about(NULL,"成功","删除成功");
 //   }
       //   write();
}

void subwidget4::on_pushButton_3_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","编号或名称不能为空");
         return;
    }

  //  else {
          for(p=readclasses.begin();p!=readclasses.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  readclasses.erase(p);
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
             }
              }

                  QMessageBox::about(NULL,"提示","请输入修改后的所有信息");
                  QString code1=ui->lineEdit->text();//读者类别（编号、名称、借阅时长限制、借阅册数限制、其它说明等readtime,readamount,other;
                  QString name1=ui->lineEdit_2->text();
                  QString readtime=ui->lineEdit_3->text();
                  QString readamount=ui->lineEdit_4->text();
                  QString other=ui->lineEdit_5->text();
                  if(code1==""||name1==""||readtime==""||readamount==""||other==""){
                      QMessageBox::critical(NULL,"失败","输入不能为空");
                      return;
                  }
                  Readclass b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text());
                readclasses.push_back(b);
                 QMessageBox::about(NULL,"成功","修改成功");
                 ui->lineEdit->clear();
                 ui->lineEdit_2->clear();
                 ui->lineEdit_3->clear();
                 ui->lineEdit_4->clear();
                 ui->lineEdit_5->clear();

      //   write();
       //QMessageBox::about(NULL,"成功","修改成功");
   // }
}

void subwidget4::on_pushButton_4_clicked()
{
    QString code=ui->lineEdit->text();
    QString name=ui->lineEdit_2->text();
    if(code==""&&name==""){
        QMessageBox::critical(NULL,"失败","编号或名称不能为空");
         return;
    }
  //  else {
          for(p=readclasses.begin();p!=readclasses.end();p++)
          {
              QString c,n;
              c= p->getnumber();
              n=p->getname();
              if(code==c||name==n)
              {
                  QString code1=p->getnumber();
                  QString name1=p->getname();
                  QString readtime=p->getreadtime();
                  QString readamount=p->getreadamount();
                  QString other=p->getother();
                  standItemModel1->setItem(0,0,new QStandardItem(code1));
                  standItemModel1->setItem(0,1,new QStandardItem(name1));
                  standItemModel1->setItem(0,2,new QStandardItem(readtime));
                  standItemModel1->setItem(0,3,new QStandardItem(readamount));
                  standItemModel1->setItem(0,4,new QStandardItem(other));
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  return;
              }
             /* else {
                  QMessageBox::critical(NULL,"失败","没有该书籍");
                  return;*/
            //  QMessageBox::critical(NULL,"失败","没有该书籍");
              }
          QMessageBox::critical(NULL,"失败","没有该类别");
       //   }
      //   write();
}

void subwidget4::on_pushButton_5_clicked()
{
    bool ok=file_readclass.open(QIODevice::WriteOnly);
    if(true==ok)
    {
      //  fileClear();
        Readclass tmp;
        QDataStream stream(&file_readclass);
        QVector<Readclass>::iterator it;
        for(it=readclasses.begin();it!=readclasses.end();it++)
        {
           tmp=*it;
           stream<<tmp.getnumber()<<tmp.getname()<<tmp.getreadtime()<<tmp.getreadamount()<<tmp.getother();
        }
     file_readclass.close();
     QMessageBox::about(NULL,"成功","保存成功");
    }
}
void subwidget4::read()
{
    bool isok=file_readclass.open(QIODevice::ReadOnly);
    if(true==isok)
    {
        QDataStream stream(&file_readclass);
            stream.device()->seek(0);
            QString code,name,readtime,readamount,other;//编号、书名、作者、所属科目、出版社、出版时间、入库时间、页数、定价
            while(!file_readclass.atEnd())
            {
               Readclass tmp1;
               stream>>code>>name>>readtime>>readamount>>other;
               tmp1.setnumber(code);
               tmp1.setname(name);
               tmp1.setreadtime(readtime);
               tmp1.setreadamount(readamount);
               tmp1.setother(other);
               readclasses.insert(num4,tmp1);
               num4++;

            }
        }
        file_readclass.close();
}
