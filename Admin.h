#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
class Admin{
private:
    QString username;
    QString password;

public:
    void set_admin_username(QString);
    void set_admin_password(QString);
    QString get_admin_username();
    QString get_admin_password();
};

#endif // ADMIN_H
