#ifndef COURSE_H
#define COURSE_H
#include "student.h"
#include "professor.h"
#include <QSet>

class course
{
private:
    QString name;
    QString code;
    QString lectureHall;
    QString time;

public:
    QVector<student> studentsinCourse;
    QVector<professor> professorsinCourse;
    QMap<QString,float> students_grades;
    course();
    course (QString name, QString code, QString lectureHall, QString time);
    void set_course_name(QString);
    void set_course_code(QString);
    void set_course_lectureHall(QString);
    void set_course_time(QString);
    QString get_course_name();
    QString get_course_code();
    QString get_course_lectureHall();
    QString get_course_time();
};

#endif // COURSE_H
