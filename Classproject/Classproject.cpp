#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include "Classproject.h"
#include <string.h>
#include <string>

using namespace std;

void person::Append_course(string course) {
    cout << course;

}
person::person() {
    cout << "hi";
}
person::person(string Name, int myNat_ID, int myage, string myUniversity_name) {
    this->Name = Name;
    Nat_ID = myNat_ID;
    age = myage;
    University_name = myUniversity_name;


}
professor::professor(string Name, int Nat_ID, int age, string University_name, int mystaff_ID) :
    person(Name, Nat_ID, age, University_name) /*, staff_ID(staff_ID)*/ {
    staff_ID = mystaff_ID;

}
professor::professor() {
    cout << "hi";
}

student::student(string Name, int Nat_ID, int age, string University_name, int mystudent_ID) :
    person(Name, Nat_ID, age, University_name) /*, student_ID(student_ID)*/ {
    student_ID = mystudent_ID;

}

// INTRODUCING PROFESSORS  

vector <professor> professors;
//SQL connection lead
sql::Connection* connect() {

    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "");
    //con->setSchema("test");
    stmt = con->createStatement();
    stmt->execute("USE  Unidata");
    stmt->execute("CREATE TABLE IF NOT EXISTS Professor(id INT, name CHAR(25),age INT, Nat_ID INT, University_Name CHAR(25))");
    stmt->execute("CREATE TABLE IF NOT EXISTS Student(id INT, name CHAR(25),age INT, Nat_ID INT, University_Name CHAR(25))");
    stmt->execute("CREATE TABLE IF NOT EXISTS Course(id INT, name CHAR(25), University_Name CHAR(25))");
    return con;
}
//Functions and methods appended from Professor class
void professor::Identification(int staff_ID) {
    cout << staff_ID;
}



void professor::showprofs() {

}

void professor::searchprofs() {

}

// comment
void professor::addprof() {
    sql::Connection* con = connect();
    sql::PreparedStatement* prep_stmt;
    string file;
    string Name;
    int Nat_ID;
    int age;
    string University_name;
    int staff_ID;
    cout << "Name:";
    cin >> Name;
    cout << "age:";
    cin >> age;
    cout << "National ID:";
    cin >> Nat_ID;
    cout << "University Name:";
    cin >> University_name;
    cout << "staff ID: ";
    cin >> staff_ID;
    professor obj1(Name, Nat_ID, age, University_name, staff_ID);
    string x = obj1.Name;
    int y = obj1.Nat_ID;
    int z = obj1.age;
    string a = obj1.University_name;
    int s = obj1.staff_ID;
    cout << "Name: " + x;  cout << "\nnational ID:y " + y; cout << "\nage: " + z; cout << "\nUniversity Name: " + a;  cout << "\nStaff ID: " + s;
    
    prep_stmt = con->prepareStatement("INSERT INTO Professor(id, age, Nat_ID, name, University_Name,) VALUES (?,?,?,?,?)");
    //prep_stmt->setInt(1, s);
    //prep_stmt->setInt(2, z);
   // prep_stmt->setInt(3, y);
    //prep_stmt->setString(4, x);
   // prep_stmt->setString(5, a);
   // prep_stmt->execute();
}

void professor::removeprof() {
    string pName;
    cout << "what is the professor's name: ";
    cin >> pName;
}


// INTRODUCING STUDENTS 

vector <student> students;
void showstudent() {
    for (student i : students) {
        cout << "students name: " << i.Name << endl;
    }
}

void student::Identification(int student_ID) {
    cout << student_ID;
}

void searchstudent() {
    string pName;
    cin >> pName;
    for (student i : students) {
        if (i.Name == pName) {
            cout << i.age << endl << i.student_ID << endl << i.University_name << endl << i.Nat_ID;
        }
    }
}
// comment
void addstudent() {
    string Name;
    int Nat_ID;
    int age;
    string University_name;
    int student_ID;
    cout << "Name:";
    cin >> Name;
    cout << "age:";
    cin >> age;
    cout << "National ID:";
    cin >> Nat_ID;
    cout << "University Name:";
    cin >> University_name;
    cout << "stdent ID: ";
    cin >> student_ID;
    student obj2(Name, Nat_ID, age, University_name, student_ID);
    string x = obj2.Name;
    int y = obj2.Nat_ID;
    int z = obj2.age;
    string a = obj2.University_name;
    int s = obj2.student_ID;
    cout << "Name: " + x;  cout << "\nnational ID: " + y; cout << "\nage: " + z; cout << "\nUniversity Name: " + a; cout << "\nStudent ID: " + s;

}



//INT MAIN
//there is a object needed to be made to use the methods of the classes.

int main()
{
    professor objprof;
    while (true) {

        int input;
        cout << "to add prof  1\n student enter  2:\n show proffs: 3\n search professsor: 4\n show student: 5\n search student: 6\n delete professor: 7\n delete student: 8\n exit: 9";

        cin >> input;
        switch (input) {
        case 1:
            system("cls");
            objprof.addprof();

            break;
        case 2:
            system("cls");
            addstudent();

            break;
        case 3:
            system("cls");            

            objprof.showprofs();

            break;
        case 4:
            system("cls");
            objprof.searchprofs();
            break;
        case 5:
            system("cls");
            searchstudent();
            break;
        case 6:
            system("cls");
            objprof.removeprof();
        case 9:
            exit(0);
            
            break;

        }
    }
}
//fsfjksjmlek
// 1. proje jadid 2. Add 3. print 4. search 5. over wright

/*
while (curser != "\n") {
    char curser;
    fseek(file, -1, SEEK_CUR)
    file.get(curser);

}
*/ 
/*bool operator==(const professor& professor, const std::string& name) {
    return professor.Name == name;
}

bool operator==(const student& student, const std::string& name) {
    return student.Name == name;
}*/
//fstream proffile;
/*void searchprofs() {
    cout << "please input the Name: ";
    string line;
    string input;
    cin >> input;
    cout << "sign";
    proffile.open("../../proffile.txt", ios::in);
    if (proffile.is_open()) {
        while (getline(proffile, line)) {
            if (line == input) {
                for (int i = 0; i < 4; i++) {
                    getline(proffile, line);
                    cout << line << endl;
                }
            }
        }
    }
}
void showprofs() {
    string line;
    //proffile.open("../../proffile.txt", ios::in);
    //if (proffile.is_open()) {
    //    while (getline(proffile, line)) {
     //       cout << line << endl;
    //    }
    }

}*/
/*void showprofs() {
    for (professor i : professors) {
        cout << "proffs name: " << i.Name << endl;
    }
}
*/
/*
filehandling 
//fstream proffile;
    //proffile.open("../../proffile.txt", ios :: out);
    //proffile << x << endl;
   // proffile << y << endl;
   // proffile << z << endl;
   // proffile << a << endl;
   // proffile << s << endl;
   // proffile.close();
*/