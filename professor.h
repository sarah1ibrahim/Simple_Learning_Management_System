#ifndef PROFESSOR_H
#define PROFESSOR_H

#include"person.h"

class professor : public person
{
private:
    QString title;
public:
    QVector<QString> professor_courses;
    professor();   
    professor(QString fName, QString lName,  QString age, QString mobile, QString email, QString title);
    void set_title(QString s);
    QString get_title();
};

#endif // PROFESSOR_H
