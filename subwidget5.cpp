#include "subwidget5.h"
#include "ui_subwidget5.h"
#include <QString>
#include <QDataStream>
#include <QFile>
#include "records.h"
#include <QMessageBox>
#include<time.h>
QFile file_record("../file_record.txt");
int num5=0;
subwidget5::subwidget5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget5)
{
    ui->setupUi(this);
    standItemModel1=new QStandardItemModel();
    standItemModel1->setHorizontalHeaderLabels(QStringList()<<"借阅编号"<<"图书编号"<<"读者编号"<<"借阅时间"<<"应还时间"<<"图书管理员编号");
    ui->records->setModel(standItemModel1);
   read();
}

subwidget5::~subwidget5()
{
    delete ui;
}

void subwidget5::on_pushButton_clicked()
{
    QMessageBox::about(NULL,"提示","借阅时间不需输入，系统自动导入");
    QString rcode=ui->lineEdit->text();//QString rcode,bcode,pcode,ltime,rtime,lcode;借阅记录（借阅编号、图书编号、读者编号、借阅时间、应还时间、图书管理员编号
    QString bcode=ui->lineEdit_2->text();
    QString pcode=ui->lineEdit_3->text();
    //QString ltime=ui->lineEdit_4->text();
    QString rtime=ui->lineEdit_5->text();
    QString lcode=ui->lineEdit_6->text();
   // const QString m=getCurrentSystemTime();
    if(rcode==""||bcode==""||pcode==""||/*ltime==""||*/rtime==""||lcode==""){
        QMessageBox::critical(NULL,"失败","输入不能为空");
        return;
    }
    Records b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),/*ui->lineEdit_4->text()*/getCurrentSystemTime(),ui->lineEdit_5->text(),
         ui->lineEdit_6->text());
  records.push_back(b);
  ui->lineEdit->clear();
  ui->lineEdit_2->clear();
  ui->lineEdit_3->clear();
  ui->lineEdit_4->clear();
  ui->lineEdit_5->clear();
  ui->lineEdit_6->clear();
  QMessageBox::about(NULL,"成功","添加成功");
//  write();
}

void subwidget5::on_pushButton_2_clicked()
{
    QString rcode=ui->lineEdit->text();
    QString bcode=ui->lineEdit_2->text();
    QString pcode=ui->lineEdit_3->text();
    if(rcode==""&&bcode==""&&pcode==""){
        QMessageBox::critical(NULL,"失败","借阅编号或图书编号或读者编号不能为空");
        return;
    }

 //   else {
          for(p=records.begin();p!=records.end();p++)
          {
              QString c,n,h;
              c= p->getrcode();
              n=p->getbcode();
              h=p->getpcode();
              if(rcode==c||bcode==n||pcode==h)
              {
                  records.erase(p);
                  QMessageBox::about(NULL,"成功","删除成功");
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  ui->lineEdit_3->clear();
                  return;
              }
            //  else {
                  QMessageBox::critical(NULL,"失败","没有该记录");
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

void subwidget5::on_pushButton_3_clicked()
{
    QString rcode=ui->lineEdit->text();
    QString bcode=ui->lineEdit_2->text();
    QString pcode=ui->lineEdit_3->text();
    if(rcode==""&&bcode==""&&pcode==""){
        QMessageBox::critical(NULL,"失败","借阅编号或图书编号或读者编号不能为空");
        return;
    }


  //  else {
          for(p=records.begin();p!=records.end();p++)
          {
              QString c,n,h;
              c= p->getrcode();
              n=p->getbcode();
              h=p->getpcode();
              if(rcode==c||bcode==n||pcode==h)
              {
                  records.erase(p);
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  ui->lineEdit_3->clear();
                  return;
             }
              }

                  QMessageBox::about(NULL,"提示","请输入修改后的所有信息");
                  QString rcode1=ui->lineEdit->text();//QString rcode,bcode,pcode,ltime,rtime,lcode;借阅记录（借阅编号、图书编号、读者编号、借阅时间、应还时间、图书管理员编号
                  QString bcode1=ui->lineEdit_2->text();
                  QString pcode1=ui->lineEdit_3->text();
                  QString ltime=ui->lineEdit_4->text();
                  QString rtime=ui->lineEdit_5->text();
                  QString lcode=ui->lineEdit_6->text();
                  if(rcode1==""||bcode1==""||pcode1==""||ltime==""||rtime==""||lcode==""){
                      QMessageBox::critical(NULL,"失败","输入不能为空");
                      return;
                  }
                  Records b(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),
                       ui->lineEdit_6->text());
                 records.push_back(b);
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

void subwidget5::on_pushButton_4_clicked()
{
    QString rcode=ui->lineEdit->text();
    QString bcode=ui->lineEdit_2->text();
    QString pcode=ui->lineEdit_3->text();
   // const QString m=getCurrentSystemTime();

    if(rcode==""&&bcode==""&&pcode==""){
        QMessageBox::critical(NULL,"失败","借阅编号或图书编号或读者编号不能为空");
        return;
    }
  //  else {
          for(p=records.begin();p!=records.end();p++)
          {
              QString c,n,h;
              c= p->getrcode();
              n=p->getbcode();
              h=p->getpcode();
              if(rcode==c||bcode==n||pcode==h)
              {
                  QString rcode11=p->getrcode();
                  QString bcode11=p->getbcode();
                  QString pcode11=p->getpcode();
                  QString ltime=p->getltime();
                  QString rtime=p->getrtime();
                  QString lcode=p->getlcode();
                  standItemModel1->setItem(0,0,new QStandardItem(rcode11));
                  standItemModel1->setItem(0,1,new QStandardItem(bcode11));
                  standItemModel1->setItem(0,2,new QStandardItem(pcode11));
                  standItemModel1->setItem(0,3,new QStandardItem(ltime));
                  standItemModel1->setItem(0,4,new QStandardItem(rtime));
                  standItemModel1->setItem(0,5,new QStandardItem(lcode));
                  ui->lineEdit->clear();
                  ui->lineEdit_2->clear();
                  ui->lineEdit_3->clear();
                  return;
              }
             /* else {
                  QMessageBox::critical(NULL,"失败","没有该书籍");
                  return;*/
            //  QMessageBox::critical(NULL,"失败","没有该书籍");
              }
          QMessageBox::critical(NULL,"失败","没有该书籍");
       //   }
      //   write();
}


void subwidget5::on_pushButton_5_clicked()
{
    bool ok=file_record.open(QIODevice::WriteOnly);
    if(true==ok)
    {
        Records tmp;
        QDataStream stream(&file_record);
        QVector<Records>::iterator it;
        for(it=records.begin();it!=records.end();it++)
        {
           tmp=*it;
           stream<<tmp.getrcode()<<tmp.getbcode()<<tmp.getpcode()<<tmp.getltime()<<tmp.getrtime()<<tmp.getlcode();


        }
     file_record.close();
     QMessageBox::about(NULL,"成功","保存成功");
    }
}
void subwidget5::read()
{
    bool isok=file_record.open(QIODevice::ReadOnly);
    if(true==isok)
    {
        QDataStream stream(&file_record);
            stream.device()->seek(0);
            QString rcode,bcode,pcode,ltime,rtime,lcode;//借阅记录（借阅编号、图书编号、读者编号、借阅时间、应还时间、图书管理员编号
            while(!file_record.atEnd())
            {
               Records tmp1;
               stream>>rcode>>bcode>>pcode>>ltime>>rtime>>lcode;
               tmp1.setrcode(rcode);
               tmp1.setbcode(bcode);
               tmp1.setpcode(pcode);
               tmp1.setltime(ltime);
               tmp1.setrtime(rtime);
               tmp1.setlcode(lcode);
               records.insert(num5,tmp1);
               num5++;

            }
        }
        file_record.close();
}
const QString subwidget5::getCurrentSystemTime()
{
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);//转为时间结构。
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d %02d:%02d:%02d",
            (int)lt->tm_year + 1900,(int)lt->tm_mon + 1,(int)lt->tm_mday,
            (int)lt->tm_hour,(int)lt->tm_min,(int)lt->tm_sec);
    return QString(date);
}
