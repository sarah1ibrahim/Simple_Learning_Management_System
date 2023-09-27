#include "professor.h"
//constructor
professor::professor(){

}

void professor::set_title(QString s){
    title=s;
}

QString professor::get_title(){
    return title;
}

professor::professor(QString first_name, QString last_name, QString age, QString mobile, QString email,QString title){
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
    this->mobile = mobile;
    this->email = email;
    this->title=title;

}
