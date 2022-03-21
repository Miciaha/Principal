#include <cstring>
#include <vector>
#include <sstream>

#include "roster.h"
#include "degree.h"

Roster::Roster() {
	*classRosterArray = new Student[10]();
}

Roster::~Roster() {
	delete * classRosterArray;
	cout << "\n\nRoster instance deconstructed.\n";
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);

	classRosterArray[classSize] = newStudent;

	classSize++;
}

void Roster::parseDataset(const string* dataset, const int datasetLen) {


	for (size_t i = 0; i < datasetLen; i++)
	{
		std::vector<string> studentInfo;

		string ID, fName, lName, email;
		int age, courseOne, courseTwo, courseThree;
		DegreeProgram degree;

		string student = *(dataset + i);

		std::stringstream ss(student);

		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			studentInfo.push_back(substr);
		}

		ID = studentInfo[0];
		fName = studentInfo[1];
		lName = studentInfo[2];
		email = studentInfo[3];
		age = std::stoi(studentInfo[4]);
		courseOne = std::stoi(studentInfo[5]);
		courseTwo = std::stoi(studentInfo[6]);
		courseThree = std::stoi(studentInfo[7]);
		degree = getDegreeEnum(studentInfo[8]);

		add(ID, fName, lName, email, age, courseOne, courseTwo, courseThree, degree);
	}
}

void Roster::remove(string studentID) {

	int arrayPosition = findStudent(studentID);

	if (arrayPosition != -1)
	{
		int rosterLen = *(&classRosterArray + 1) - classRosterArray;
		classSize = classSize - 1;

		Student* temp[10];
		*temp = new Student[10]();

		for (size_t i = 0; i < classSize; i++)
		{
			if (i < arrayPosition) {
				temp[i] = classRosterArray[i];
			}
			else if (i >= arrayPosition)
			{
				temp[i] = classRosterArray[i+1];
			}
		}

		std::copy(temp, temp + rosterLen, classRosterArray);
		cout << "\nStudent " << studentID << " removed from class roster.";
		return;
	}
	return;
}


void Roster::printAll() {
	cout << "\n\n\t\t\t\t\tCourse Roster\t\t\t";
	cout << "\n ______________________________________________________________________________________\n";
	cout << "| ID ";
	cout << "| First Name ";
	cout << "|  Last Name  ";
	cout << "|         Email          ";
	cout << "| Age ";
	cout << "| CourseDays ";
	cout << "|  Degree  |";
	cout << "\n|--------------------------------------------------------------------------------------|";

	for (size_t i = 0; i < classSize; i++)
	{
		classRosterArray[i]->print();
	}
	cout << "\n|______________________________________________________________________________________|\n";
}

void Roster::printAverageDaysInCourse() {
	cout << "\nAverage number of days left in courses:\n";
	for (size_t i = 0; i < classSize; i++)
	{
		string ID = classRosterArray[i]->getID();
		printAverageDaysInCourse(ID);
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	
	int arrayPosition = findStudent(studentID);

	if (arrayPosition != -1)
	{
		int* coursesPtr = classRosterArray[arrayPosition]->getCourseCompletion();
		int courseAvg = (coursesPtr[0] + coursesPtr[1] + coursesPtr[2]) / 3;

		cout << studentID << ": " << courseAvg << endl;
	}

	return;
}

void Roster::printInvalidEmails() {
	int invalidEmailCount = 0;
	cout << "\nInvalid email addresses:\n";

	for (size_t i = 0; i < classSize; i++)
	{
		string email = classRosterArray[i]->getEmail();


		const char* atSymbolPtr = strchr(email.c_str(), '@');
		const char* dotSymbolPtr = strchr(email.c_str(), '.');
		const char* spacePtr = strchr(email.c_str(), ' ');

		if (atSymbolPtr == NULL || dotSymbolPtr == NULL || spacePtr != NULL)
		{
			invalidEmailCount++;
			cout << "  -" << email << endl;
		}
	}

	if (invalidEmailCount == 0)
	{
		cout << "\nAll email addressess are valid.\n";
	}
	cout << endl;
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "\n\t\t\t\t" << getDegreeString(degreeProgram) << " Degree Students";
	cout << "\n ______________________________________________________________________________________\n";
	cout << "| ID ";
	cout << "| First Name ";
	cout << "|  Last Name  ";
	cout << "|         Email          ";
	cout << "| Age ";
	cout << "| CourseDays ";
	cout << "|  Degree  |";
	cout << "\n|--------------------------------------------------------------------------------------|";

	int memberCount = 0;

	for (size_t i = 0; i < classSize; i++)
	{
		if (degreeProgram == classRosterArray[i]->getDegree()) {
			classRosterArray[i]->print();
			memberCount++;
		}
	}
	cout << "\n|______________________________________________________________________________________|\n";

	if (memberCount == 0)
	{
		cout << "\nUnable to find students in the " << getDegreeString(degreeProgram) << " program.\n";
	}
}


int Roster::findStudent(string studentID) {
	for (size_t i = 0; i < classSize; i++)
	{
		if (studentID == classRosterArray[i]->getID())
		{
			return i;
		}
	}

	cout << "\nStudent ID " << studentID << " was not found in class roster.";

	return -1;
}