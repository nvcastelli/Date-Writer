/*
Name: Nicholas Castelli
Program: Programming Assignment #2
Recitation Time: Thursday 5:15-6:30
*/

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <cstdlib>

using namespace std;

//Default Constants
const int DEFAULTMONTH = 1;
const int DEFAULTDAY = 1;
const int DEFAULTYEAR = 2000;
const char DEFAULTFORMAT = 'D';


//make defaults for mon, day, year and char

class Date
{
public:
	//default construct.
	Date();

	Date(const int, const int q = 1, const int w = 2000);

//These three be the get(accesor) functions
	int GetMonth();

	int GetDay();

	int GetYear();



	//Prompts user to enter a date
	//NEEDS TO ERROR CHECK
	//assume data entered in the form mm/dd/yyyy
void Input();

	//Output data to screen
	//three different possibilities:
	//Default- M/D/Y (ex. 10/4/1998)
	//Two-Digit- mm/dd/yy (ex. 10/04/98)
	//Long- month D, Y (ex. Oct 4, 1998)
void Show();

	//This function should move the date forward by the
	//number of calendar days given in the argument. 
	//Default value on the parameter is 1 day
void Increment(int numDays = 1);

	//Used by the increment function to increment by one
	//Function also addresses problem when changing years and months
void IncrementByOne();

	//returns -1,0,1xsw
	//-1 if the calling object comes first chronologically,
	//0 if the objects are the same date, and 1 if the parameter
	//object comes first chronologically
int Compare(const Date& d);

	//Allows user to change the format of Show function
	//Pass in a char
	//'D' = Default format 
	//'T' = Two-Digit format 
	//'L' = Long format
	//Error check for invalid entry
bool SetFormat(char f);

	//Set to False if invalid date entered
	//more error checking
bool Set(int m, int d, int y);

//overloads the '<<' operator
friend ostream& operator << (ostream& newout, const Date& d);

// CLASS CONSTANTS

private:

	int month, day, year;
	//declare this value
	char format;

};

#endif

