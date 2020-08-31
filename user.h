#ifndef USER_H
#define USER_H
#include <QString>
class User
{
protected:
    QString number,name ;//用户编号，姓名

public:
    User(QString n,QString na){number=n;name=na;}
    User(){}
    QString getnumber()
    {
        return number;
    }
    QString getname()
    {
        return name;
    }
    void setnumber(QString n1)
    {
        number=n1;
    }
    void setname(QString n2)
    {
        name=n2;
    }


};
class Student:public User
{
protected:
    QString sex,age,type,college,rutime,bitime;//学号、名称、性别、年龄、类别、所属学院、入学时间、毕业时间

public:
    Student(QString n,QString na,QString s,QString a1,QString c,QString t,QString r,QString b):User(n,na)
    {
        sex=s;age=a1;type=t;college=c;rutime=r;bitime=b;
    }
    Student(){}
    void Setsex(QString sex1)
    {
        sex=sex1;
    }
    void Setage(QString age1)
    {
        age=age1;
    }
    void Setcollege(QString college1)
    {
        college=college1;
    }
    void Setrutime(QString rutime1)
    {
        rutime=rutime1;
    }
    void Settype(QString type1)
    {
       type=type1;
    }
    void Setbitime(QString bitime1)
    {
        bitime=bitime1;
    }
    QString Getsex(){return sex;}
    QString Getage(){return age;}
    QString Getcollege(){return college;}
    QString Getrutime(){return rutime;}
    QString Gettype(){return type;}
    QString Getbitime(){return bitime;}

};
class Teacher:public User
{
protected:
     QString sex1,age1,college1,rutime1;//工号、名称、性别、年龄、所属学院、入职时间
public:
    Teacher( QString n11, QString n21, QString s1, QString a11, QString c1, QString r1):User(n11,n21)
    {
        sex1=s1;age1=a11;college1=c1;rutime1=r1;
    }
    Teacher(){}
    void Setsex1( QString sex11)
    {
        sex1=sex11;
    }
    void Setage1( QString age11)
    {
        age1=age11;
    }
    void Setcollege1(QString college11)
    {
        college1=college11;
    }
    void Setrutime1(QString rutime11)
    {
        rutime1=rutime11;
    }
    QString Getsex1(){return sex1;}
    QString Getage1(){return age1;}
    QString Getcollege1(){return college1;}
    QString Getrutime1(){return rutime1;}
};
class Librarian:public User
{
protected:
    QString post;//图书管理员工号、名称、岗位
public:
    Librarian(QString n1,QString n2,QString pp):User(n1,n2)
    {
        post=pp;
    }
   Librarian(){}
    void Setpost(QString post1)
    {
        post=post1;
    }
    QString getpost()
    {
        return post;
    }

};
//读者类别（编号、名称、借阅时长限制、借阅册数限制、其它说明等）
class Readclass:public User
{
protected:
    QString readtime,readamount,other;
public:
    Readclass(QString nn,QString nnn,QString r,QString re,QString o):User(nn,nnn)
    {
        readtime=r;readamount=re;other=o;
    }
    Readclass(){}
    void setreadtime(QString r1)
    {
        readtime=r1;
    }
    void setreadamount(QString r2)
    {
        readamount=r2;
    }
    void setother(QString o1)
    {
        other=o1;
    }
    QString getreadtime()
    {return readtime;}
    QString getreadamount()
    {return readamount;}
    QString getother()
    {return other;}
};
#endif // USER_H
