#ifndef ROSTER_H
#define ROSTER_H 

#include <iostream>

#include "student.h"

class Roster
{
public:
	// Constructor intializing an empty array of student pointers.
	Roster();

	// Deconstructor freeing space allocated for pointers
	~Roster();

	// Add students to roster using all student details
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	
	// Remove student from class roster
	void remove(string studentID);

	// Add multiple students to class roster using a string array
	void parseDataset(const string* dataset, const int datasetLen);

	// Print average course days for all students in the roster. 
	void printAverageDaysInCourse();

	/**
	 * Print average course day for specified student
	 *
	 * @param student ID string
	 *
	 */
	void printAverageDaysInCourse(string studentID);

	// Print invalid emails found in class roster.
	void printInvalidEmails();

	// Print all students found in course roster.
	void printAll();

	/**
	 * Print students in specified degree program.
	 *
	 * @param degree program enum used for searching through roster.
	 */
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:

	/**
	* Search class roster for student using student ID.
	*
	* @param student ID string used for roster search.
	* @return position of student in class array as an int, or NULL if student is not found.
	*/
	int findStudent(string studentID);

	// Check roster size to ensure additional data can fit in the array. Expands array if necessary.
	void checkRosterSize();

	// Array of pointers pointing to Student class objects.
	Student* classRosterArray[10];

	// Size of the class roster.
	int classSize = 0;
};

#endif // !ROSTER_H
