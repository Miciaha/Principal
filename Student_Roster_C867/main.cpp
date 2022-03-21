#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

#include "student.h"
#include "degree.h"
#include "roster.h"

static void title() {

	// save default formatting
	ios init(NULL);
	init.copyfmt(cout);

	cout << setw(83) << setfill('*');
	cout << "\n*" << setw(80) << setfill(' ') << "*";
	cout << "\n*\t\t    SCRIPTING AND PROGRAMMING - APPLICATIONS - C867\t\t*";
	cout << "\n*\t\t\t\t\tC++\t\t\t\t\t*";
	cout << "\n*" << setw(80) << setfill(' ') << "*";
	cout << "\n*\t\t\t\t    Miciaha Ivey\t\t\t\t*";
	cout << "\n*\t\t\t\t       mivey37\t\t\t\t\t*";
	cout << "\n*" << setw(80) << setfill(' ') << "*";
	cout.copyfmt(init);
	cout << "\n" << setw(104) << setfill('*');

}

int main()
{
	title();

	// Student data input as defined by course scenario
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
								   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
								   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								   "A5,Miciaha,Ivey,mivey37@wgu.edu,27, 19,30,43,SOFTWARE" };	// Addition of my personal information to student table
	
	// Class roster setup
	Roster classRoster = Roster();

	// Retrieving length of dataset and passing values for roster to parse
	const int datasetCount = *(&studentData + 1) - studentData;
	classRoster.parseDataset(studentData, datasetCount);

	// Printing all students in the class roster
	classRoster.printAll();

	// Printing all invalid emails
	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse();

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");
	classRoster.printAll();

	classRoster.remove("A3");
}