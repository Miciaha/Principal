# Student Roster Project
## Project Story

I am hired as a contractor to help a university migrate an existing student system to a new platform using C++ language. Since the application already exists, its requirements exist as well, and they are outlined in the next section. I am responsible for implementing the part of the system based on the following requirements. A list of data is provided as part of these requirements. This part of the system is responsible for reading and manipulating the provided data.

## Console Screenshot
![RunConsole](https://user-images.githubusercontent.com/14229230/159360037-fc768034-b689-4060-ac3d-2427420b341d.PNG)

## Project Requirements

| # | Title | Description | Status | Notes |
|---|-------|-------------|--------|-------|
| 1 | Modify Data Table | Add personal information as last element to the provided student data table. | ✔️ | [Data Table](#student-data-table)|
| 2 | IDE Setup | Create C++ Project in IDE with required files. | ✔️ | Refer to items 3 - 6 for required files. Requirements for individual files are listed under the [Class Requirements](#class-details) section.| 
| 3 | Create Degree Header | Create degree.h and define enumerated type DegreeProgram. |✔️| [Degree header details](#degree)|
| 4 | Create Student Class | Create student.h and student.cpp. Include required variables and functions.  |✔️| [Student class details](#student)|
| 5 | Create Roster Class | Create roster.h and roster.cpp. Include required variables and functions. |✔️| [Roster class details](#roster)|
| 6 | Include Main File | Add required functionality to main function within main.cpp |✔️| [Main details](#main-function-requirements)|
| 7 | Console Screenshot | Provide a screenshot of the application running in the console window. |✔️| [Screenshot](#console-screenshot)

## Project Resources

### Student Data Table
![StudentTable](https://user-images.githubusercontent.com/14229230/159360087-9da85a3b-7089-48ea-a5f2-76812d3aba88.PNG)

Must import table using the provided string array:
```cpp
const string studentData[] = 
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE"}
```

## Class Details
Below are the descriptions for each of the classes in the project. Project requirements are identified with `📋`, while quality of life additions are prefaced with `💡`.

### Degree

Constructor/Deconstructor:
N/A

Data:
|📋/💡| Type | Name | Description | Status | Notes |
|---|------|------|-------------|--------|-------|
|📋| `Enum` | DegreeProgram | Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE. |✔️| The enum data type had to be converted to type `enum class` due to scoping issues. [Refer to C++ guidelines for more information](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#enum3-prefer-class-enums-over-plain-enums) |

Functions:
|📋/💡| ReturnType | Name | Parameters | Description | Status | Notes |
|---|------|------|------|-------|--------|-------|
|💡| `DegreeProgram` | getDegreeEnum | `string degreeName` | Converts degree name from `string` to `DegreeProgram` |✔️| Quality of life function for parsing data from string table.|
|💡| `string` | getDegreeString | `DegreeProgram degree` | Converts `DegreeProgram` to `string` |✔️| Quality of life function for printing student details easier.

---

### Student

Constructor/Deconstructor:
|📋/💡| Name | Parameters| Description | Status |
|---|------|------|-------|------|
|💡| `Student()` | | Creates an empty student object with all data intialized to `empty`, `NULL`, or `NONE`. | Student ID |✔️|
|📋| `Student()` |`string id`, `string fname`, `string lname`, `string studentEmail`, `int studentAge`, `int courseOne`, `int courseTwo`, `int courseThree`, `DegreeProgram degreeName` | Creates a student object using all data. | Student ID |✔️|

Data:
|📋/💡| Type | Name | Description | Status |
|---|------|------|-------------|--------|
|📋| `string` | ID | Student ID |✔️|
|📋| `string` | firstName | Student first name |✔️|
|📋| `string` | lastName | Student last name |✔️| 
|📋| `string` | email | Student email address |✔️| 
|📋| `int` | age | Student age |✔️|
|📋| `int[3]` | courseCompletion | array of number of days to complete each course |✔️|
|📋| `DegreeProgram` | degree | Student degree program |✔️|

Functions:
| 📋/💡 | ReturnType | Name | Parameters | Description | Status |
|---|------|------|------|-------|--------|
|📋| `void` | setID | `string studentID` | Set student ID |✔️|
|📋| `void` | setFirstName | `string studentFirstName` | Set student first name. |✔️|
|📋| `void` | setLastName | `string studentLastName` | Set student last name. |✔️|
|📋| `void` | setEmail | `string studentEmail` |Set student email. |✔️|
|📋| `void` | setAge | `int studentAge` |Set student age. |✔️|
|📋| `void` | setDegree | `string degreeName` |Set student degree. |✔️|
|📋| `void` | setCourseCompletion | `int courseOne`,`int courseTwo`,`int courseThree` |Set student ID |✔️|
|📋| `string` | getID | | Get student ID |✔️|
|📋| `string` | getFirstName | | Get student first name. |✔️|
|📋| `string` | getLastName | | Get student last name. |✔️|
|📋| `string` | getEmail | | Get student email. |✔️|
|📋| `int` | getAge | | Get student age. |✔️|
|📋| `DegreeProgram` | getDegree | | Get student degree. |✔️|
|📋| `int*` | getCourseCompletion | | Get student ID |✔️|
|📋| `void` | print | | Print student information |✔️|

Templates:
|📋/💡| Name | Description | Status | Notes |
|---|------|-------------|--------|-------|
|💡| prettifyResults | Organizes strings for printing data in table format |✔️| Created table format to improve readability for the client. Tab separated lists would flow out of the console window and required constant resizing. |

---

### Roster
Constructor/Deconstructor:
|📋/💡| Name | Description | Status |
|---|------|------|-------------|
|📋| `Roster()` | Constructor intializing an empty array of student pointers.|✔️|
|📋| `~Roster()` | Deconstructor freeing space allocated for array of student pointers. |✔️|

Data:
|📋/💡| Type | Name | Description | Status |
|---|------|------|-------------|--------|
|📋| `Student*[]` | classRosterArray | Array of pointers to Student objects |✔️|
|💡| `int` | classSize | Current size of class roster |✔️|

Functions:
| 📋/💡 | ReturnType | Name | Parameters | Description | Status |
|---|------|------|-------|------|--------|
|📋| `void` | add | `string studentID`, `string firstName`, `string lastName`, `string emailAddress`, `int age`, `int daysInCourse1`, `int daysInCourse2`, `int daysInCourse3`, `DegreeProgram degreeprogram` | Add students to roster using all student details. |✔️|
|📋| `void` | remove | `string studentID` | Remove student from class roster. |✔️|
|💡| `void` | parseDataset | `const string* dataset`, `const int datasetLen`| Add multiple students to class roster using a const string array |✔️|
|💡| `void` | printAverageDaysInCourse | | Print average course days for all students in the roster. |✔️|
|📋| `void` | printAverageDaysInCourse | `string studentID` | Print average course day for specified student |✔️|
|📋| `void` | printInvalidEmails | | Print invalid emails found in class roster. |✔️|
|📋| `void` | printAll | | Print all students found in course roster. |✔️|
|📋| `void` | printByDegreeProgram | `DegreeProgram degreeProgram` | Print students in specified degree program. |✔️|
|💡| `int` | findStudent | `string studentID` | Search class roster for student using student ID. |✔️|

---

### Main Function Requirements
Convert the following psuedocode and run in main
``` cpp
classRoster.printAll();

classRoster.printInvalidEmails();

//loop through classRosterArray and for each element:

classRoster.printAverageDaysInCourse(/*current_object's student id*/);

classRoster.printByDegreeProgram(SOFTWARE);

classRoster.remove("A3");

classRoster.printAll();

classRoster.remove("A3");

//expected: the above line should print a message saying such a student with this ID was not found.
```
