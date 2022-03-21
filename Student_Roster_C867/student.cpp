#include "student.h"
#include <iomanip>

Student::Student() {
	ID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = NULL;
	*courseCompletion = NULL;
	degree = DegreeProgram::NONE;
}

Student::Student(string id, string fname, string lname, string studentEmail, int studentAge, int courseOne, int courseTwo, int courseThree, DegreeProgram degreeName) {
	ID = id;
	firstName = fname;
	lastName = lname;
	email = studentEmail;
	age = studentAge;
	courseCompletion[0] = courseOne;
	courseCompletion[1] = courseTwo;
	courseCompletion[2] = courseThree;
	degree = degreeName;
}

void Student::setID(string studentID) {
	ID = studentID;
}

void Student::setFirstName(string studentFirstName) {
	firstName = studentFirstName;
}

void Student::setLastName(string studentLastName) {
	lastName = studentLastName;
}

void Student::setEmail(string studentEmail) {
	email = studentEmail;
}

void Student::setAge(int studentAge) {
	age = studentAge;
}

void Student::setDegree(string degreeName) {

	degree = getDegreeEnum(degreeName);
}

void Student::setCourseCompletion(int courseOne, int courseTwo, int courseThree) {
	courseCompletion[0] = courseOne;
	courseCompletion[1] = courseTwo;
	courseCompletion[2] = courseThree;
}

string Student::getID() {
	return ID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int* Student::getCourseCompletion() {
	return courseCompletion;
}

DegreeProgram Student::getDegree() {
	return degree;
}

template<typename T> void prettifyResults(T t,int width) {
	cout << "|" << left << setw(width) << setfill(' ') << t ;
}

void Student::print() {
	string courseDays = "{" + to_string(courseCompletion[0]) + ", " + to_string(courseCompletion[1]) + ", " + to_string(courseCompletion[2]) + "}";

	// save default formatting
	ios init(NULL);
	init.copyfmt(cout);
	
	cout << "\n";
	prettifyResults(ID,4);
	prettifyResults(firstName,12);
	prettifyResults(lastName,13);
	prettifyResults(email,24);
	prettifyResults(age,5);
	prettifyResults(courseDays,10);
	prettifyResults(getDegreeString(degree),10);
	cout << "|";
	cout.copyfmt(init);
}
