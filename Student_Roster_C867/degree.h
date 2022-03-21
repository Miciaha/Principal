#ifndef DEGREE_H
#define DEGREE_H

#include <string>

// Enum class defining all degrees.
enum class DegreeProgram
{
	NONE = 0,
	SECURITY = 1,
	NETWORK = 2,
	SOFTWARE = 3
};

/*
* Convert degree name string to type DegreeProgram.
* 
* @params Degree name as string.
* @return DegreeProgram enum type if degree was found, or NONE if the degree was not found.
*/
static DegreeProgram getDegreeEnum(std::string degreeName) {
	if (degreeName == "SECURITY") {
		return DegreeProgram::SECURITY;
	}
	else if (degreeName == "NETWORK") {
		return DegreeProgram::NETWORK;
	}
	else if (degreeName == "SOFTWARE") {
		return DegreeProgram::SOFTWARE;
	}
	else
	{
		return DegreeProgram::NONE;
	}
}

/*
* Convert DegreeProgram enum into string for printing.
* 
* @params DegreeProgram enum.
* @return String with the same name as the DegreeProgram enum.
*/
static std::string getDegreeString(DegreeProgram degree) {
	switch (degree)
	{
	case DegreeProgram::NONE:
		return "None";
		break;
	case DegreeProgram::SECURITY:
		return "Security";
		break;
	case DegreeProgram::NETWORK:
		return "Network";
		break;
	case DegreeProgram::SOFTWARE:
		return "Software";
		break;
	}
}
#endif // !DEGREE_H