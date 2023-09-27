#include "student.h"

student::student(){}

student::student(QString first_name, QString last_name, QString age, QString mobile, QString email, QString grade){
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->mobile = mobile;
    this->email = email;
    this->grade=grade;
}

void student::set_grade(QString g){
    grade = g;
}

QString student::get_grade(){
    return grade;
}

QString student::get_student()
{
    return (first_name +" "+ last_name);
}

