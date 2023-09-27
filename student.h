#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include<QMap>
#include"person.h"
class student : public person
{
private:
    QString grade;
public:
    QMap<QString, float> student_courses_grades;
    student();
    student(QString first_name, QString last_name, QString age, QString mobile, QString email, QString grade);
    void set_grade(QString g);
    QString get_grade();
    QString get_student();
    bool operator <(const student &other) const {
        return code < other.code;
    }
};

#endif // STUDENT_H
