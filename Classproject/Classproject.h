#pragma once
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
/*
class course {
	int ID;
	string name;
};
*/

class person {
public:
	string Name;
	int Nat_ID;
	int age;
	bool active = true;
	string University_name;
	vector<string> courses;
public:
	void Append_course(string course);
	person(string Name, int Nat_ID, int age, string University_name);
	person();
};


class professor : public person {
public:
	int staff_ID;
	string Study_branch;
	void addprof();
	void removeprof();
	void showprofs();
	void searchprofs();
public:
	void Identification(int staff_ID);
	professor(string Name, int Nat_ID, int age, string University_name, int staff_ID);
	professor();
};


class student : public person {
public:
	int student_ID;


public:
	void Identification(int student_ID);
	student(string Name, int Nat_ID, int age, string University_name, int student_ID);


};

class Uni {
	public:
		vector<string> studentmembers;
		vector<string> profmembers;
	public:	
		void setstudent(string student);
		void setprof(string professor);
		void removestd(string student);
		void removeprof(string professor);
};
