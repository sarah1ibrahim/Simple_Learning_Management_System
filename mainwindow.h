#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMessageBox>
#include<QObject>
#include <QMainWindow>
#include"professor.h"
#include"student.h"
#include"course.h"
#include<QSet>
#include<QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_exitToLoginScreen_clicked();

    void on_pushButton_back_to_main_clicked();

    void on_pushButton_prfList_clicked();

    void on_pushButton_cancel_add_professor_clicked();

    void on_pushButton_addprf_clicked();

    void set_professor_data();

    void set_student_data();

    void on_pushButton_addNewProfessor_clicked();

    void on_tableWidget_professorList_cellClicked(int row, int column);

    void on_pushButton_back_to_main_2_clicked();

    void on_pushButton_addNewStudent_clicked();

    void on_pushButton_cancelStudentAdd_clicked();

    void on_pushButton_addStudent_clicked();

    void on_pushButton_stdList_clicked();

    void on_tableWidget_studentsList_cellClicked(int row, int column);

    void on_pushButton_8_clicked();

    void on_pushButton_searchStudent_2_clicked();

    void found_student_info(int i);

    void on_pushButton_searchStudent_clicked();

    void on_pushButton_back_to_search_clicked();

    void on_pushButton_back_to_professorListPage_clicked();

    void on_pushButton_search_professor_clicked();

    void on_pushButton_searchProfessor_clicked();

    void found_professor_info(int i);

    void on_pushButton_back_to_search_professo_clicked();

    void on_pushButton_back_to_main_list_clicked();

    void on_pushButton_cancel_search_course_clicked();

    void on_pushButton_to_search_course_page_clicked();

    void on_pushButton_add_course_clicked();

    void on_pushButton_cancel_add_course_clicked();

    void on_pushButton_search_course_2_clicked();

    void on_pushButton_courseList_clicked();

    void on_pushButton_back_to_courseList_page_clicked();

    void display_course_info(int i);

    void display_students_grades(int i);

    void on_pushButton_add_course_2_clicked();

    void set_course_data();

    void on_tableWidget_courseList_cellDoubleClicked(int row, int column);

    void on_pushButton_export_student_clicked();

    void on_pushButton_export_professors_clicked();

    void on_pushButton_add_professor_to_course_clicked();

    void on_pushButton_cancel_add_professor_to_course_clicked();

    void on_pushButton_add_professor_to_course_2_clicked();

    QString getProfessor(int i);

    void on_pushButton_cancel_add_student_clicked();

    void on_pushButton_add_student_to_course_2_clicked();

    void on_pushButton_add_student_to_course_clicked();

    void on_pushButton_back_to_professorsList_screen_clicked();

    void on_tableWidget_professorList_cellDoubleClicked(int row, int column);

    bool is_professor_in_course(QVector<professor>, professor);

    void on_tableWidget_studentsList_cellDoubleClicked(int row, int column);

    void on_pushButton_bak_to_studentsList_clicked();

    void on_pushButton_export_cources_clicked();

    void on_tableWidget_students_grades_cellDoubleClicked(int row, int column);

    void on_pushButton_back_to_coursesList_clicked();

    bool is_valid_mobile_number(QString);

    bool is_valid_name(QString);

private:
    int professor_code = 0;
    int student_code = 0;
    QVector<course> coursesList;
    QSet<QString> l3001_times = {"8:30-10:00", "10:15-11:45","12:15-1:45","2:00-3:30"};
    QSet<QString> l3002_times = {"8:30-10:00", "10:15-11:45","12:15-1:45","2:00-3:30"};
    QSet<QString> l3003_times = {"8:30-10:00", "10:15-11:45","12:15-1:45","2:00-3:30"};
    QSet<QString> courses_codes;
    QVector<professor> professorsList;
    QVector<student> studentsList;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
