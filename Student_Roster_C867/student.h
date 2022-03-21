#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>

#include "degree.h"

using namespace std;

class Student
{
public:
	
	// Constructor to create an 'empty' student object with all information initialized.
	Student();
	
	// Constructor to create student object using all student information.
	Student(string id, string fname, string lname, string studentEmail, int studentAge, int courseOne, int courseTwo, int courseThree, DegreeProgram degreeName);

	// Set student ID.
	void setID(string studentID);

	// Set student first name.
	void setFirstName(string studentFirstName);

	// Set student last name.
	void setLastName(string studentLastName);
	
	// Set student email.
	void setEmail(string studentEmail);
	
	// Set student age.
	void setAge(int studentAge);

	// Set student degree @param Degree name as string. Function will convert to enum.
	void setDegree(string degreeName);

	// Set course completion days @param days remaining to complete three courses.
	void setCourseCompletion(int courseOne, int courseTwo, int courseThree);

	// Get student ID.
	string getID();

	// Get student first name.
	string getFirstName();

	// Get student last name.
	string getLastName();

	// Get student email.
	string getEmail();

	// Get student age.
	int getAge();

	// Get course completion days as array.
	int* getCourseCompletion();

	// Get Degree Program as enum type DegreeProgram.
	DegreeProgram getDegree();

	// Print student information.
	void print();

private:
	string ID;
	string firstName;
	string lastName;
	string email;
	int	age;
	int courseCompletion[3];
	DegreeProgram degree;
};

#endif // !STUDENT_H
