#include "course.h"

course::course(){}

course::course(QString name, QString code, QString lectureHall, QString time)
{
    this->name = name;
    this->code = code;
    this->lectureHall = lectureHall;
    this->time = time;
    this->code = code;
}

void course::set_course_name(QString s)
{
    name = s;
}

void course::set_course_code(QString s)
{
    code = s;
}

void course::set_course_lectureHall(QString s)
{
    lectureHall = s;
}

void course::set_course_time(QString s)
{
    time = s;
}

QString course::get_course_name()
{
    return name;
}

QString course::get_course_code()
{
    return code;
}

QString course::get_course_lectureHall()
{
    return lectureHall;
}

QString course::get_course_time()
{
    return time;
}



