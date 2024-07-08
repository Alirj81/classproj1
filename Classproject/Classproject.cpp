#include <iostream>
#include "Classproject.h"
#include <string.h>
#include <string>
#include <fstream>
using namespace std;


void person::Append_course(string course) {
    cout << course;

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

student::student(string Name, int Nat_ID, int age, string University_name, int mystudent_ID) :
    person(Name, Nat_ID, age, University_name) /*, student_ID(student_ID)*/ {
    student_ID = mystudent_ID;

}

// INTRODUCING PROFESSORS  

vector <professor> professors;
void showprofs() {
    for (professor i : professors) {
        cout << "proffs name: " << i.Name << endl;
    }
}

void professor::Identification(int staff_ID) {
    cout << staff_ID;
}

/*bool operator==(const professor& professor, const std::string& name) {
    return professor.Name == name;
}

bool operator==(const student& student, const std::string& name) {
    return student.Name == name;
}*/

void searchprofs() {
    string pName;
    cin >> pName;
    for (auto i : professors) {
        if (i.Name == pName) {
            cout << i.age << endl << i.staff_ID << endl << i.University_name << endl << i.Nat_ID;
        }
    }
}
// comment
void addprof() {
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
    fstream proffile;
    proffile.open("proffile.txt", ios :: out);
    proffile << x << endl;
    proffile << y << endl;
    proffile << z << endl;
    proffile << a << endl;
    proffile << s << endl;
    proffile.close();
    
}

void removeprof() {
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

int main()
{
    //ofstream proffile("proffile.txt");
   // proffile.close();
    //ofstream studfile("studfile.txt");
   // studfile.close();
    while (true) {

        int input;
        cout << "to add prof  1\n student enter  2:\n show proffs: 3\n search professsor: 4\n show student: 5\n search student: 6\n delete professor: 7\n delete student: 8\n exit: 9";

        cin >> input;
        switch (input) {
        case 1:
            system("cls");
            addprof();
            //ofstream proffile("proffile.txt");
            //proffile.close();
            break;
        case 2:
            system("cls");
            addstudent();
            //ofstream studfile("studfile.txt");
           // studfile.close();
            break;
        case 3:
            system("cls");            
            //ofstream proffile("proffile.txt");
            showprofs();
            //proffile.close();
            //getchar();
            break;
        case 4:
            system("cls");
           // ofstream studfile("studfile.txt");
            showstudent();
            //studfile.close();
            break;
        case 5:
            system("cls");
            searchstudent();
            break;
        case 6:
            system("cls");
            removeprof();
        case 9:
            exit(0);
            break;

        }
    }
}

// 1.serch prof OK 2.search stu OK 3.khoshgel 4.pop