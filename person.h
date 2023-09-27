#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class person {
protected :
    QString first_name;
    QString last_name;
    QString age;
    QString mobile;
    QString email;
    int code;

public:
    void set_first_name(QString s){
        first_name=s;
    }
    void set_last_name(QString s){
        last_name=s;
    }
    void set_age(QString s){
        age=s;
    }
    void set_mobile(QString s){
        mobile=s;
    }
    void set_email(QString s){
        email= s + "@gmail.com";
    }
    void set_code(int s){
        code = s;
    }
    QString get_first_name(){
       return first_name;
    }
    QString get_last_name(){
        return last_name;
    }
    QString get_age(){
        return age;
    }
    QString get_mobile(){
        return mobile;
    }
    QString get_email(){
        return email;
    }
    int get_code(){
        return code;
    }
};

#endif // PERSON_H
