#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<iostream>
#include<QLineEdit>
#include <algorithm>
#include<QVector>
#include<QVectorIterator>
using namespace std;
#include"course.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Learning Management System");
    //start from login screen
    ui->stackedWidget->setCurrentWidget(ui->login_screen);
    //ui->stackedWidget->setCurrentWidget(ui->stdListPage);
    //set comboboxes items
    QComboBox * lecture_halls = ui->stackedWidget->findChild<QComboBox*>("comboBox_lectureHall");
    QComboBox * times = ui->stackedWidget->findChild<QComboBox*>("comboBox_time");
    lecture_halls->addItem("3001");
    lecture_halls->addItem("3002");
    lecture_halls->addItem("3003");
    times->addItem("8:30-10:00");
    times->addItem("10:15-11:45");
    times->addItem("12:15-1:45");
    times->addItem("2:00-3:30");
    QLineEdit* a = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mailstd");
    //a->setReadOnly(false)
}
//destructor
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    //get username and password
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    //check if username and password are correct
    if(username == "Ahmed" && password == "123"){
        ui->stackedWidget->setCurrentWidget(ui->main_choose_list_screen);
    }
    else{
        QMessageBox::warning(this,"Login", "Username and Password are incorrect");
    }
}

//open login screen and delete previous data in lineEdits
void MainWindow::on_pushButton_exitToLoginScreen_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->login_screen);
    QLineEdit* username = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_username");
    QLineEdit* password = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_password");
    username->clear();
    password->clear();
}

//open main list screen
void MainWindow::on_pushButton_back_to_main_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_choose_list_screen);
}

//open professors list screen
void MainWindow::on_pushButton_prfList_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->professors_List_screen);
}


void MainWindow::on_pushButton_addNewProfessor_clicked()
{
    //open add professor screen
    ui->stackedWidget->setCurrentWidget(ui->add_professor_info_screen);
    // set a pointer to all lineedits
    QLineEdit * first_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_fName");
    QLineEdit * last_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_lName");
    QLineEdit * Age = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_age");
    QLineEdit * mail = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mail");
    QLineEdit * mob = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mob");
    QLineEdit * pTitle = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_title");
    //clear previous texts
    first_name->clear();
    last_name->clear();
    Age->clear();
    mail->clear();
    mob->clear();
    pTitle->clear();
}

void MainWindow::on_pushButton_cancel_add_professor_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->professors_List_screen);
}

void MainWindow::on_pushButton_back_to_main_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_choose_list_screen);
}

void MainWindow::on_pushButton_stdList_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stdListPage);
}

void MainWindow::on_pushButton_addNewStudent_clicked()
{
    //open add student screen
    ui->stackedWidget->setCurrentWidget(ui->addStudentPage);
    // set a pointer to all lineedits
    QLineEdit * first_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_fNamestd");
    QLineEdit * last_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_lNamestd");
    QLineEdit * Age = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_agestd");
    QLineEdit * mail = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mailstd");
    QLineEdit * mob = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mobstd");
    QLineEdit * stdgrade = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_grade");
    //clear previous texts
    first_name->clear();
    last_name->clear();
    Age->clear();
    mail->clear();
    mob->clear();
    stdgrade->clear();
}


void MainWindow::on_pushButton_cancelStudentAdd_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stdListPage);
}
//cancel search student and return to students list page
void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stdListPage);
}

void MainWindow::on_pushButton_searchStudent_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->search_student_page);
    // set a pointer to all lineedits
    QLineEdit *stdCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_stdCode");
    // clear previous texts
    stdCode->clear();
}


void MainWindow::on_pushButton_back_to_search_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->search_student_page);
    QLineEdit *stdCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_stdCode");
    stdCode->clear();
}

void MainWindow::on_pushButton_back_to_professorListPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->professors_List_screen);
}


void MainWindow::on_pushButton_addprf_clicked()
{
    // set a pointer to all lineedits
    QLineEdit * first_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_fName");
    QLineEdit * last_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_lName");
    QLineEdit * Age = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_age");
    QLineEdit * mail = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mail");
    QLineEdit * mob = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mob");
    QLineEdit * pTitle = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_title");
    // store texts in QString
    QString fName = first_name->text();
    QString lName = last_name->text();
    QString age = Age->text();
    QString email = mail->text();
    QString mobile = mob->text();
    QString title = pTitle->text();

    //create new professor
    professor p1;
    //display a warning message if on field or more are empty
    if(fName.isEmpty() || lName.isEmpty() || title.isEmpty() || age.isEmpty() || email.isEmpty()){
        QMessageBox::warning(this,"Add professor","Please fill all fields");
    }
    else{
        // set professor data
        if(!is_valid_name(fName) || !is_valid_name(lName)){
            QMessageBox::warning(this,"Add professor","Invalid name");
        }
        p1.set_first_name(fName);
        p1.set_last_name(lName);
        p1.set_title(title);
        if(30 > age.toInt() || age.toInt() > 60){
            QMessageBox::warning(this,"Add professor","Invalid age");
        }
        else{
            p1.set_age(age);
            p1.set_email(email);

            // display a warning message if mobile number is empty or size less than 11
            if(mobile.isEmpty() || mobile.size() != 11 || !is_valid_mobile_number(mobile)){
                QMessageBox::warning(this,"Add professor","Invalid mobile number");
            }
            else{
                //set professor data and store professor in vector of professor
                p1.set_mobile(mobile);
                professor_code++;
                p1.set_code(professor_code);
                professorsList.push_back(p1);
                // function to set professor data in a table
                set_professor_data();
                //return to all professors list screen
                ui->stackedWidget->setCurrentWidget(ui->professors_List_screen);
            }
        }
    }
}

// function to set and display professor data in table
void MainWindow::set_professor_data()
{
    // define a pointer to professors table
    QTableWidget *prof_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_professorList");
    // set number of columns and set table header
    prof_info_table->setColumnCount(7);
    QStringList header;
    header<<"First name"<<"Last name"<<"Age"<<"Code"<<"    E-mail    "<<"  Mobile  "<<" Title ";
    prof_info_table->setHorizontalHeaderLabels(header);
    int s = professorsList.size();
    // set data in table
    for(int i = 0; i < s; i++){
        // set number of rows to the vector size (#professors)
        prof_info_table->setRowCount(s);
        // define pointer to all data items
        QTableWidgetItem *fName = new QTableWidgetItem;
        QTableWidgetItem *lName = new QTableWidgetItem;
        QTableWidgetItem *age = new QTableWidgetItem;
        QTableWidgetItem *code = new QTableWidgetItem;
        QTableWidgetItem *email = new QTableWidgetItem;
        QTableWidgetItem *mobile = new QTableWidgetItem;
        QTableWidgetItem *title = new QTableWidgetItem;
        // set text for ith professor
        fName->setText(professorsList[i].get_first_name());
        lName->setText(professorsList[i].get_last_name());
        code->setText(QString::number(professorsList[i].get_code()));
        email->setText(professorsList[i].get_email());
        mobile->setText(professorsList[i].get_mobile());
        age->setText(professorsList[i].get_age());
        title->setText(professorsList[i].get_title());
        // set data of ith professor in the ith row
        prof_info_table->setItem(i,0,fName);
        prof_info_table->setItem(i,1,lName);
        prof_info_table->setItem(i,2,age);
        prof_info_table->setItem(i,3,code);
        prof_info_table->setItem(i,4,email);
        prof_info_table->setItem(i,5,mobile);
        prof_info_table->setItem(i,6,title);
    }
}

//display data of a professor in label
void MainWindow::on_tableWidget_professorList_cellClicked(int row, int column)
{
    // define a pointer to all professors table and a pointer to the label
    QTableWidget *prof_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_professorList");
    QLabel *professor_info_txt = ui->stackedWidget->findChild<QLabel*>("professor_info");
    //set the data from table in label
    professor_info_txt->setText("First Name:" + prof_info_table->item(row,0)->text() + "\n" +
                                "Last Name:" + prof_info_table->item(row,1)->text() + "\n" +
                                "Age:" + prof_info_table->item(row,2)->text() + "\n" +
                                "Code:" + prof_info_table->item(row,3)->text() + "\n" +
                                "E-mail:" + prof_info_table->item(row,4)->text() + "\n" +
                                "Mobile:" + prof_info_table->item(row,5)->text() + "\n" +
                                "Title:" + prof_info_table->item(row,6)->text()
                                );
}

void MainWindow::on_pushButton_addStudent_clicked()
{
    // set a pointer to all lineedits
    QLineEdit * first_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_fNamestd");
    QLineEdit * last_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_lNamestd");
    QLineEdit * Age = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_agestd");
    QLineEdit * mail = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mailstd");
    QLineEdit * mob = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_mobstd");
    QLineEdit * stdgrade = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_grade");
    // store texts in QString
    QString fName = first_name->text();
    QString lName = last_name->text();
    QString age = Age->text();
    QString email = mail->text();
    QString mobile = mob->text();
    QString grade = stdgrade->text();
    //create new student
    student s1;
    //display a warning message if on field or more are empty
    if(fName.isEmpty() || lName.isEmpty() || grade.isEmpty() || age.isEmpty() || email.isEmpty()){
        QMessageBox::warning(this,"Add student","please fill all fields");
    }
    else{
        // set student data
        if(!is_valid_name(fName) || !is_valid_name(lName)){
            QMessageBox::warning(this,"Add student","Invalid name");
        }
        else{
            s1.set_first_name(fName);
            s1.set_last_name(lName);
            s1.set_grade(grade);
            if(age.toInt() < 18){
                QMessageBox::warning(this,"Add student","Invalid age");
            }
            else{
                s1.set_age(age);
                s1.set_email(email);
                // display a warning message if mobile number is empty or size less than 11
                if(mobile.isEmpty() || mobile.size() != 11 || !is_valid_mobile_number(mobile)){
                    QMessageBox::warning(this,"Add student","Invalid mobile number");
                }
                else{
                    // set student data and store student in vector
                    s1.set_mobile(mobile);
                    student_code++;
                    s1.set_code(student_code);
                    studentsList.push_back(s1);
                    // function to set data in table
                    set_student_data();
                    // return to all students list
                    ui->stackedWidget->setCurrentWidget(ui->stdListPage);
                }
            }
        }
    }
}

void MainWindow::set_student_data()
{
    // define a pointer to professors table
    QTableWidget *std_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_studentsList");
    std_info_table->setColumnCount(7);
    QStringList header;
    header<<"First name"<<"Last name"<<"Age"<<"Code"<<"E-mail"<<"Mobile"<<"Grade";
    std_info_table->setHorizontalHeaderLabels(header);
    int s = studentsList.size();
    for(int i = 0; i < s; i++){
        std_info_table->setRowCount(s);
        // define pointer to all data items
        QTableWidgetItem *fName = new QTableWidgetItem;
        QTableWidgetItem *lName = new QTableWidgetItem;
        QTableWidgetItem *age = new QTableWidgetItem;
        QTableWidgetItem *code = new QTableWidgetItem;
        QTableWidgetItem *email = new QTableWidgetItem;
        QTableWidgetItem *mobile = new QTableWidgetItem;
        QTableWidgetItem *grade = new QTableWidgetItem;
        // set the data items
        fName->setText(studentsList[i].get_first_name());
        lName->setText(studentsList[i].get_last_name());
        code->setText(QString::number(studentsList[i].get_code()));
        email->setText(studentsList[i].get_email());
        mobile->setText(studentsList[i].get_mobile());
        age->setText(studentsList[i].get_age());
        grade->setText(studentsList[i].get_grade());
        // set items in table
        std_info_table->setItem(i,0,fName);
        std_info_table->setItem(i,1,lName);
        std_info_table->setItem(i,2,age);
        std_info_table->setItem(i,3,code);
        std_info_table->setItem(i,4,email);
        std_info_table->setItem(i,5,mobile);
        std_info_table->setItem(i,6,grade);
    }
}


void MainWindow::on_tableWidget_studentsList_cellClicked(int row, int column)
{
    // define a pointer to all students table and a pointer to the label
    QTableWidget *std_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_studentsList");
    QLabel *student_info_txt = ui->stackedWidget->findChild<QLabel*>("student_info");
    // set student data in label from all students table
    student_info_txt->setText("First Name:" + std_info_table->item(row,0)->text() + "\n" +
                                "Last Name:" + std_info_table->item(row,1)->text() + "\n" +
                                "Age:" + std_info_table->item(row,2)->text() + "\n" +
                                "Code:" + std_info_table->item(row,3)->text() + "\n" +
                                "E-mail:" + std_info_table->item(row,4)->text() + "\n" +
                                "Mobile:" + std_info_table->item(row,5)->text() + "\n" +
                                "Grade:" + std_info_table->item(row,6)->text()
                                );
}


void MainWindow::on_pushButton_searchStudent_2_clicked()
{
    // define a pointer to lineedit that contains the code
    QLineEdit *stdCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_stdCode");
    // store student code
    QString student_code = stdCode->text();
    // convert code to int
    int std_code = student_code.toInt();
    bool flag = false;
    int i;
    // find the student that has the code if exist
    for(i = 0 ; i < studentsList.size(); i++){
        if(studentsList[i].get_code() == std_code){
            flag = true;
            break;
        }
    }
    if(!flag)
     QMessageBox::information(this,"Search","Student not found");
    // open the found student page and call function to display student data
    else{
        ui->stackedWidget->setCurrentWidget(ui->selected_student_info_page);
        //on_tableWidget_studentsList_cellDoubleClicked(std_code,1);
        found_student_info(i);

    }
}

void MainWindow::found_student_info(int i)
{
    // sefine a pointer to label
    QLabel *student_info_txt = ui->stackedWidget->findChild<QLabel*>("label_student_info");
    // set student data in label
    student_info_txt->setText("First Name:" + studentsList[i].get_first_name() + "\n" +
                                "Last Name:" + studentsList[i].get_last_name() + "\n" +
                                "Age:" + studentsList[i].get_age()+ "\n" +
                                "Code:" + QString::number(studentsList[i].get_code()) + "\n" +
                                "E-mail:" + studentsList[i].get_email() + "\n" +
                                "Mobile:" + studentsList[i].get_mobile() + "\n" +
                                "Grade:" + studentsList[i].get_grade()
                                );
    QTableWidget *std_course_grade_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_courses_grades");
    std_course_grade_table->setColumnCount(2);
    QStringList header;
    header << "Courses"<<"Grades";
    std_course_grade_table->setHorizontalHeaderLabels(header);
    int s = studentsList[i].student_courses_grades.size();
    int row2 = 0;
    // display courses and grades of a student
    for(QMap<QString,float>::iterator it = studentsList[i].student_courses_grades.begin(); it != studentsList[i].student_courses_grades.end(); ++it){
        std_course_grade_table->setRowCount(s);
        QTableWidgetItem *course = new QTableWidgetItem;
        QTableWidgetItem *grade = new QTableWidgetItem;
        course->setText(it.key());
        grade->setText(QString::number(it.value()));
        std_course_grade_table->setItem(row2,0,course);
        std_course_grade_table->setItem(row2,1,grade);
        row2++;
    }

}

void MainWindow::on_pushButton_search_professor_clicked()
{
    // define a pointer to lineEdit that contains professor code
    QLineEdit *profCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_professor_code");
    // store professor code then convert to int
    QString professor_code = profCode->text();
    int prof_code = professor_code.toInt();
    bool flag = false;
    int i;
    // find the professor that has the code if exist
    for(i = 0 ; i < professorsList.size(); i++){
        if(professorsList[i].get_code() == prof_code){
            flag = true;
            break;
        }
    }
    if(!flag)
        QMessageBox::information(this,"Search","professor not found");
    // open the found professor screen and call function to display professor data
    else{
        ui->stackedWidget->setCurrentWidget(ui->selected_professor_page);
        found_professor_info(i);

    }
}


void MainWindow::on_pushButton_searchProfessor_clicked()
{
    // open search professor screen and clear the previous texts in lineEdit
    ui->stackedWidget->setCurrentWidget(ui->search_professor_page);
    QLineEdit *profCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_professor_code");
    profCode->clear();
}

void MainWindow::found_professor_info(int i)
{
    // define pointer to label
    QLabel *professor_info_txt = ui->stackedWidget->findChild<QLabel*>("label_selected_professor_info");
    // display found professor data in label
    professor_info_txt->setText("First Name:" + professorsList[i].get_first_name() + "\n" +
                                "Last Name:" + professorsList[i].get_last_name() + "\n" +
                                "Age:" + professorsList[i].get_age()+ "\n" +
                                "Code:" + QString::number(professorsList[i].get_code()) + "\n" +
                                "E-mail:" + professorsList[i].get_email() + "\n" +
                                "Mobile:" + professorsList[i].get_mobile() + "\n" +
                                "Title:" + professorsList[i].get_title()
                                );
    QTableWidget *prof_courses_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_professor_courses");
    prof_courses_table->setColumnCount(1);
    QStringList header;
    header << "Courses";
    prof_courses_table->setHorizontalHeaderLabels(header);
    int s = professorsList[i].professor_courses.size();
    //display courses of a professor
    for(int j = 0; j < professorsList[i].professor_courses.size(); j++){
        prof_courses_table->setRowCount(s);
        QTableWidgetItem * course = new QTableWidgetItem;
        course->setText(professorsList[i].professor_courses[j]);
        prof_courses_table->setItem(j,0,course);
    }

}


void MainWindow::on_pushButton_back_to_search_professo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->search_professor_page);
    QLineEdit *profCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_professor_code");
    profCode->clear();

}

void MainWindow::on_pushButton_back_to_main_list_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->main_choose_list_screen);
}

void MainWindow::on_pushButton_cancel_search_course_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->course_list_page);
}

void MainWindow::on_pushButton_to_search_course_page_clicked()
{
    // open search course screen and clear the previous texts in lineEdit
    ui->stackedWidget->setCurrentWidget(ui->search_course_page);
    QLineEdit *courseCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_code_search");
    courseCode->clear();
}


void MainWindow::on_pushButton_add_course_clicked()
{
    // open add course screen and clear the previous texts in lineEdit
    ui->stackedWidget->setCurrentWidget(ui->course_add_page);
    QLineEdit * course_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_name");
    QLineEdit * course_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_code");
    course_code->clear();
    course_name->clear();
}


void MainWindow::on_pushButton_cancel_add_course_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->course_list_page);
}


void MainWindow::on_pushButton_search_course_2_clicked()
{
    // define pointer to lineEdit that contains the course code then store the code in QString
    QLineEdit *courseCode = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_code_search");
    QString course_code = courseCode->text();
    bool flag = false;
    // find the course that has the code if exists
    int i;
    for(i = 0 ; i < coursesList.size(); i++){
        if(coursesList[i].get_course_code() == course_code){
            flag = true;
            break;
        }
    }
    if(!flag)
     QMessageBox::information(this,"Search","course not found");
    else{
       // open course info page and call function to display course data
       ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
       display_course_info(i);
    }
}


void MainWindow::on_pushButton_courseList_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->course_list_page);
}

void MainWindow::on_pushButton_back_to_courseList_page_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->course_list_page);
    QTableWidget* students_grades = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_students_grades");
    students_grades->setRowCount(0);
}


void MainWindow::display_course_info(int i)
{
    // define pointer to labels
    QLabel * course_code_txt = ui->stackedWidget->findChild<QLabel*>("label_course_code");
    QLabel * course_info_txt = ui->stackedWidget->findChild<QLabel*>("label_selected_course_info");
    // store #professors in class
    int j = coursesList[i].professorsinCourse.size();
    course_info_txt->setText("Course Name:" + coursesList[i].get_course_name());
    //display course data
    if(j == 0){
        course_info_txt->setText("Course Name: " + coursesList[i].get_course_name() + "\n" +
                                    "Lecture Hall: " + coursesList[i].get_course_lectureHall() + "\n" +
                                    "Time: " + coursesList[i].get_course_time()
                                    );
        course_code_txt->setText(coursesList[i].get_course_code());
    }
    if(j == 1){
        course_info_txt->setText("Course Name: " + coursesList[i].get_course_name() + "\n" +
                                    "Professors: " + coursesList[i].professorsinCourse[0].get_first_name() +"\n "+
                                    "Lecture Hall: " + coursesList[i].get_course_lectureHall() + "\n" +
                                    "Time: " + coursesList[i].get_course_time()
                                    );
        course_code_txt->setText(coursesList[i].get_course_code());
    }
    if(j == 2){
        course_info_txt->setText("Course Name: " + coursesList[i].get_course_name() + "\n" +
                                    "Professors: " + coursesList[i].professorsinCourse[0].get_first_name() +" & " +
                                                    coursesList[i].professorsinCourse[1].get_first_name() +"\n" +
                                    "Lecture Hall: " + coursesList[i].get_course_lectureHall() + "\n" +
                                    "Time: " + coursesList[i].get_course_time()
                                    );
        course_code_txt->setText(coursesList[i].get_course_code());
    }
    if(j == 3){
        course_info_txt->setText("Course Name: " + coursesList[i].get_course_name() + "\n" +
                                 "Professors: " + coursesList[i].professorsinCourse[0].get_first_name() +" & " +
                                                 coursesList[i].professorsinCourse[1].get_first_name() +" & " +
                                                 coursesList[i].professorsinCourse[2].get_first_name() +"\n" +
                                "Lecture Hall: " + coursesList[i].get_course_lectureHall() + "\n" +
                                "Time: " + coursesList[i].get_course_time()
                                );
        course_code_txt->setText(coursesList[i].get_course_code());
    }
        // call function to display students in class with their grades
        display_students_grades(i);

}

void MainWindow::display_students_grades(int i)
{
    //define pointer to tabel
    QTableWidget *students_grades_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_students_grades");
    // set #columns and the table header
    students_grades_table->setColumnCount(2);
    QStringList header;
    header<<"Student name"<<"Grade";
    students_grades_table->setHorizontalHeaderLabels(header);
    int s = coursesList[i].students_grades.size();
    // display students and their grades
    int row = 0;
    for(QMap<QString,float>::iterator it = coursesList[i].students_grades.begin(); it != coursesList[i].students_grades.end(); ++it){
        students_grades_table->setRowCount(s);
        QTableWidgetItem *stdName = new QTableWidgetItem;
        QTableWidgetItem *grade = new QTableWidgetItem;
        stdName->setText(it.key());
        grade->setText(QString::number(it.value()));
        students_grades_table->setItem(row,0,stdName);
        students_grades_table->setItem(row,1,grade);
        row++;
    }

}

void MainWindow::on_pushButton_add_course_2_clicked()
{
    // define pointers to lineEdits and comboboxes in page
    QLineEdit * course_name = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_name");
    QLineEdit * course_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_course_code");
    QComboBox * lecture_halls = ui->stackedWidget->findChild<QComboBox*>("comboBox_lectureHall");
    QComboBox * times = ui->stackedWidget->findChild<QComboBox*>("comboBox_time");
    // store the selected items in QString
    QString course_time = times->currentText();
    QString course_lectureHall = lecture_halls->currentText();
    //check if time or hall have been already used
    bool flag = true;
    for(int i = 0; i < coursesList.size();i++){
        if(course_lectureHall == coursesList[i].get_course_lectureHall() && course_time == coursesList[i].get_course_time()){
            QMessageBox::warning(this,"warning","choose another time or hall");
            flag = false;
        }
    }
    // get course name and code
    if(flag){
        QString c_name = course_name->text();
        QString code = course_code->text();
        //create new course
        course c1;
        // check if all data is valid
        if(courses_codes.find(code) != courses_codes.end()){

            QMessageBox::warning(this, "warning","invalid course code");
        }
        else{
            courses_codes.insert(code);

            if(code.isEmpty() || c_name.isEmpty()){
                QMessageBox::warning(this,"Add student","please fill all fields");
            }
            else{
                // set course data and store course in courses vector
                c1.set_course_name(c_name);
                c1.set_course_code(code);
                c1.set_course_time(course_time);
                c1.set_course_lectureHall(course_lectureHall);
                coursesList.push_back(c1);
                //call function to set course data
                set_course_data();
                ui->stackedWidget->setCurrentWidget(ui->course_list_page);
            }
        }
    }
}

//function to set course data in table
void MainWindow::set_course_data()
{
    QTableWidget *courses_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_courseList");
    courses_info_table->setColumnCount(4);
    QStringList header;
    header<<"Course name"<<"Code"<<"Lecture hall"<<"Time";
    courses_info_table->setHorizontalHeaderLabels(header);
    int s = coursesList.size();
    // loop on courses list and set their data in table
    for(int i = 0; i < s; i++){
    courses_info_table->setRowCount(s);
    QTableWidgetItem *Name = new QTableWidgetItem;
    QTableWidgetItem *code = new QTableWidgetItem;
    QTableWidgetItem *lectureHall = new QTableWidgetItem;
    QTableWidgetItem *time = new QTableWidgetItem;
    Name->setText(coursesList[i].get_course_name());
    code->setText(coursesList[i].get_course_code());
    lectureHall->setText(coursesList[i].get_course_lectureHall());
    time->setText(coursesList[i].get_course_time());
    courses_info_table->setItem(i, 0, Name);
    courses_info_table->setItem(i, 1, code);
    courses_info_table->setItem(i, 2, lectureHall);
    courses_info_table->setItem(i, 3, time);
    }
}

//function to export all students data in csv file
void MainWindow::on_pushButton_export_student_clicked()
{
    // create csv file
    QFile file("C:/Users/ashra/OneDrive/Documents/try6/students.csv");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","file not open");
    }
    //set data in csv file
    QTextStream stream(&file);
    stream<<"First name"<<","<<"Last name"<<","<<"Age"<<","<<"Code"<<","<<"E-mail"<<"," <<"Mobile"<<","
<<"Grade"<<"\n";
    for(int i =0; i < studentsList.size(); i++){
        stream<<studentsList[i].get_first_name()<<","<<studentsList[i].get_last_name()<<","<<studentsList[i].get_age()<<","
        <<studentsList[i].get_code()<<","<<studentsList[i].get_email()<<","<<studentsList[i].get_mobile()<<","<<studentsList[i].get_grade()<<"\n";
        }
    stream<<"\n"<<"\n";
    for(int i =0; i < studentsList.size(); i++){
        stream<<"student: "<<studentsList[i].get_student()<<"\n";
        stream<<"Course"<<","<<"Course grade"<<"\n";
        for(QMap<QString,float>::iterator it = studentsList[i].student_courses_grades.begin(); it != studentsList[i].student_courses_grades.end(); ++it){
            stream<<it.key()<<","<<it.value()<<"\n";
    }
}
    file.flush();
    file.close();
    QMessageBox::information(this,"export","Exported succefully");
}



//function to export all professors data to csv file
void MainWindow::on_pushButton_export_professors_clicked()
{
    // create csv file
    QFile file("C:/Users/ashra/OneDrive/Documents/try6/professors.csv");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","file not open");
    }
    // set data in csv file
    QTextStream stream(&file);
    stream<<"First name"<<","<<"Last name"<<","<<"Age"<<","<<"Code"<<","<<"E-mail"<<"," <<"Mobile"<<","
<<"Tiltle"<<"\n";
    for(int i =0; i < professorsList.size(); i++){
        stream<<professorsList[i].get_first_name()<<","<<professorsList[i].get_last_name()<<","<<professorsList[i].get_age()<<","
        <<professorsList[i].get_code()<<","<<professorsList[i].get_email()<<","<<professorsList[i].get_mobile()<<","<<professorsList[i].get_title()<<"\n";

        }
    for(int i =0; i < professorsList.size(); i++){
        stream<<"professor: "<<professorsList[i].get_first_name()<<" "<<professorsList[i].get_last_name()<<"\n";
        stream<<"Courses: "<<"\n";
        for(int j = 0; j < professorsList[i].professor_courses.size(); j++){
            stream<<professorsList[i].professor_courses[j]<<"\n";
        }
    }
    file.flush();
    file.close();
    QMessageBox::information(this,"export","Exported succefully");
}


void MainWindow::on_pushButton_add_professor_to_course_clicked()
{
    //open add screen page
    ui->stackedWidget->setCurrentWidget(ui->add_professor_to_course_page);
    // define a pointer to lineEdit and clear the previous text
    QLineEdit* professor_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_professor_code_2");
    professor_code->clear();
}

// return to course info page
void MainWindow::on_pushButton_cancel_add_professor_to_course_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
}


void MainWindow::on_pushButton_add_professor_to_course_2_clicked()
{
    //get professor code
    QLineEdit* professor_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_professor_code_2");
    QString prof_code = professor_code->text();
    bool flag = false;
    //search professor that has the code
    int j;
    for(int i = 0; i< professorsList.size();i++){
        if(QString::number(professorsList[i].get_code()) == prof_code){
            //get the current course code
            QLabel *course_code_txt = ui->stackedWidget->findChild<QLabel*>("label_course_code");
            QString course_code = course_code_txt->text();
            //get the course name and store it in professor courses vector
            //store the added professor in course professors
            for( j = 0; j < coursesList.size(); j++){
                if((coursesList[j].get_course_code() == course_code) && !is_professor_in_course(coursesList[j].professorsinCourse, professorsList[i]) && coursesList[j].professorsinCourse.size() <= 3){
                    professorsList[i].professor_courses.push_back(coursesList[j].get_course_name());
                    coursesList[j].professorsinCourse.push_back(professorsList[i]);
                    flag = true;
                    break;
                }
            }
        }
    }
        if(!flag){
            QMessageBox::warning(this,"warning","invalid code");
        }
        else{
            display_course_info(j);
            ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
        }
    }

// function that returns professor full name
QString MainWindow::getProfessor(int i)
{
    return(professorsList[i].get_first_name() + " " + professorsList[i].get_last_name() + "," +
           "code: " + QString::number(professorsList[i].get_code()));

}

//function to display selected course info
void MainWindow::on_tableWidget_courseList_cellDoubleClicked(int row, int column)
{
    //call function to display course info
    display_course_info(row);
    ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
}


void MainWindow::on_pushButton_cancel_add_student_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
}



void MainWindow::on_pushButton_add_student_to_course_2_clicked()

{
    //get student code
    QLineEdit* student_grade = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_student_grade");
    QLineEdit* student_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_student_code");
    QString code = student_code->text();
    QString grade;
    //set grade = 0 if user did not write any thing
    if(student_grade->text().isEmpty()){
        grade = QString::number(0);
    }
    else{
       grade = student_grade->text();
    }
    bool flag = false;
    // search student that has the code
    int j;
    for(int i = 0; i < studentsList.size(); i++){
        if(QString::number(studentsList[i].get_code()) == code){
                //get course code
                QLabel *course_code_txt = ui->stackedWidget->findChild<QLabel*>("label_course_code");
                QString code = course_code_txt->text();
                //get the course name and store it in student courses map with the grade
                //store the added student in course students map with grades
                for( j = 0; j < coursesList.size(); j++){
                    if(coursesList[j].get_course_code() == code){
                        coursesList[j].studentsinCourse.push_back(studentsList[i]);
                        studentsList[i].student_courses_grades.insert(coursesList[j].get_course_name(), grade.toFloat());
                        coursesList[j].students_grades.insert(studentsList[i].get_student(), grade.toFloat());
                        flag = true;
                        break;
                    }
                }

        }
    }
        if(!flag){
            QMessageBox::warning(this,"warning","code does not exist");
        }
        else{
            //call function to display course data
            display_course_info(j);
            ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
        }
    }


void MainWindow::on_pushButton_add_student_to_course_clicked()
{
    //open page and remove all previouse texts in lineEdits
    ui->stackedWidget->setCurrentWidget(ui->add_student_to_course_page);
    QLineEdit* student_grade = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_student_grade");
    QLineEdit* student_code = ui->stackedWidget->findChild<QLineEdit*>("lineEdit_student_code");
    student_code->clear();
    student_grade->clear();
}


void MainWindow::on_pushButton_back_to_professorsList_screen_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->professors_List_screen);
}


void MainWindow::on_tableWidget_professorList_cellDoubleClicked(int row, int column)
{
    //define pointers to label and table
    ui->stackedWidget->setCurrentWidget(ui->selected_professor_page);
    QLabel* professor_info = ui->stackedWidget->findChild<QLabel*>("label_selected_professor_info");
    QTableWidget *prof_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_professorList");
    // display professor data in label
    professor_info->setText("First Name: " + prof_info_table->item(row,0)->text() + "\n" +
                                "Last Name: " + prof_info_table->item(row,1)->text() + "\n" +
                                "Age: " + prof_info_table->item(row,2)->text() + "\n" +
                                "Code: " + prof_info_table->item(row,3)->text() + "\n" +
                                "E-mail: " + prof_info_table->item(row,4)->text() + "\n" +
                                "Mobile: " + prof_info_table->item(row,5)->text() + "\n" +
                                "Title: " + prof_info_table->item(row,6)->text() + "\n"
);
    //display data in table of professor courses
    QTableWidget *prof_courses_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_professor_courses");
    prof_courses_table->setColumnCount(1);
    QStringList header;
    header << "Courses";
    prof_courses_table->setHorizontalHeaderLabels(header);
    int s = professorsList[row].professor_courses.size();
    for(int i = 0; i < professorsList[row].professor_courses.size(); i++){
        prof_courses_table->setRowCount(s);
        QTableWidgetItem * course = new QTableWidgetItem;
        course->setText(professorsList[row].professor_courses[i]);
        prof_courses_table->setItem(i,0,course);
    }

}

bool MainWindow::is_professor_in_course(QVector<professor> v, professor p)
{
    bool flag = false;
    for(auto i: v){
        if(i.get_code() == p.get_code()){
            flag = true;
            break;
        }
    }
    return flag;

}


void MainWindow::on_tableWidget_studentsList_cellDoubleClicked(int row, int column)
{
    //define pointers to label and table
    ui->stackedWidget->setCurrentWidget(ui->selected_student_info_page);
    QLabel* student_info = ui->stackedWidget->findChild<QLabel*>("label_student_info");
    QTableWidget *std_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_studentsList");
    // display student data in label
    student_info->setText("First Name: " + std_info_table->item(row,0)->text() + "\n" +
                                "Last Name: " + std_info_table->item(row,1)->text() + "\n" +
                                "Age: " + std_info_table->item(row,2)->text() + "\n" +
                                "Code: " + std_info_table->item(row,3)->text() + "\n" +
                                "E-mail: " + std_info_table->item(row,4)->text() + "\n" +
                                "Mobile: " + std_info_table->item(row,5)->text() + "\n" +
                                "Grade: " + std_info_table->item(row,6)->text()
    );
    //display data in table of student courses and grades
    QTableWidget *std_course_grade_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_courses_grades");
    std_course_grade_table->setColumnCount(2);
    QStringList header;
    header << "Courses"<<"Grades";
    std_course_grade_table->setHorizontalHeaderLabels(header);
    int s = studentsList[row].student_courses_grades.size();
    int row2 = 0;
    //loop to set student courses and grades
    for(QMap<QString,float>::iterator it = studentsList[row].student_courses_grades.begin(); it != studentsList[row].student_courses_grades.end(); ++it){
        std_course_grade_table->setRowCount(s);
        QTableWidgetItem *course = new QTableWidgetItem;
        QTableWidgetItem *grade = new QTableWidgetItem;
        course->setText(it.key());
        grade->setText(QString::number(it.value()));
        std_course_grade_table->setItem(row2,0,course);
        std_course_grade_table->setItem(row2,1,grade);
        row2++;
    }
}


void MainWindow::on_pushButton_bak_to_studentsList_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stdListPage);
}


void MainWindow::on_pushButton_export_cources_clicked()
{
    // create csv file
    QFile file("C:/Users/ashra/OneDrive/Documents/try6/courses.csv");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","file not open");
    }
    //set data in csv file
    QTextStream stream(&file);
    stream<<"Course name"<<","<<"Code"<<","<<"Lecture hall"<<","<<"Time"<<","<<"Professor 1"<<"Professor 2"<<"Professor 3"<<"\n";
    for(int i =0; i < coursesList.size(); i++){
        stream<<coursesList[i].get_course_name()<<","<<coursesList[i].get_course_code()<<","<<coursesList[i].get_course_lectureHall()<<","
        <<coursesList[i].get_course_time()<<",";
        for(int j = 0; j< coursesList[i].professorsinCourse.size(); j++){
            stream<<coursesList[i].professorsinCourse[j].get_first_name()<<" "<< coursesList[i].professorsinCourse[j].get_last_name()<<",";
        }
        stream<<"\n";
    }
    for(int j = 0; j< coursesList.size(); j++){
        stream<<"Course: "<<coursesList[j].get_course_name()<<"\n";
        stream<< "Student name"<<","<<"Course grade"<<"\n";
        for(QMap<QString,float>::iterator it = coursesList[j].students_grades.begin(); it != coursesList[j].students_grades.end(); ++it){
            stream<<it.key()<<","<<it.value()<<"\n";
        }
    }
    file.flush();
    file.close();
    QMessageBox::information(this,"export","Exported succefully");
}


void MainWindow::on_tableWidget_students_grades_cellDoubleClicked(int row, int column)
{
    ui->stackedWidget->setCurrentWidget(ui->selected_student_courses_grades_page);
    //define pointers to label and table
    QLabel* student_info = ui->stackedWidget->findChild<QLabel*>("label_selected_student_basic_info");
    QTableWidget *std_info_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_studentsList");
    QTableWidget *std_grades_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_students_grades");
    QString student_name = std_grades_table->item(row,0)->text();
    int i;
    // get code of the student
    for(i = 0; i < studentsList.size(); i++){
        if(studentsList[i].get_student() == student_name)
            break;
    }
    // display student data from table in label
    student_info->setText("First Name: " + std_info_table->item(i,0)->text() + "\n" +
                                "Last Name: " + std_info_table->item(i,1)->text() + "\n" +
                                "Age: " + std_info_table->item(i,2)->text() + "\n" +
                                "Code: " + std_info_table->item(i,3)->text() + "\n" +
                                "E-mail: " + std_info_table->item(i,4)->text() + "\n" +
                                "Mobile: " + std_info_table->item(i,5)->text() + "\n" +
                                "Grade: " + std_info_table->item(i,6)->text()
    );
    //display data in table of student courses and grades
    QTableWidget *std_course_grade_table = ui->stackedWidget->findChild<QTableWidget*>("tableWidget_selected_student_course_grade_info");
    std_course_grade_table->setColumnCount(2);
    QStringList header;
    header << "Courses"<<"Grades";
    std_course_grade_table->setHorizontalHeaderLabels(header);
    int s = studentsList[i].student_courses_grades.size();
    int count = 0;
    //loop to display student, registered courses and grades
    for(QMap<QString,float>::iterator it = studentsList[i].student_courses_grades.begin(); it != studentsList[i].student_courses_grades.end(); ++it){
        std_course_grade_table->setRowCount(s);
        QTableWidgetItem *course = new QTableWidgetItem;
        QTableWidgetItem *grade = new QTableWidgetItem;
        course->setText(it.key());
        grade->setText(QString::number(it.value()));
        std_course_grade_table->setItem(count,0,course);
        std_course_grade_table->setItem(count,1,grade);
        count++;
    }
}


void MainWindow::on_pushButton_back_to_coursesList_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->choosed_course_info_page);
}

bool MainWindow::is_valid_mobile_number(QString s)
{
    for(auto i : s){
        if( i < QChar(48) || i > QChar(57))
            return false;
    }
    return true;
}

bool MainWindow::is_valid_name(QString s)
{
    for(auto i : s){
        if((i > QChar(96) && i < QChar(123)) || (i > QChar(64) && i < QChar(91)))
            return true;
    }
    return false;
}

