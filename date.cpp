//date.cpp file
//program accomplishes the following Extra Credits:
//Overloading the << operator
//and
//Julian Years (without leapyear)

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include "date.h"

using namespace std;

//next three are const arrays used in the program
static const string ListOfMonths[] =
{" ","Jan","Feb","Mar","Apr","May","June",
"July", "Aug","Sept","Oct","Nov", "Dec"};

 const string TWODIGETNUMBERS[] =
 {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10",
 "11", "12", "13", "14", "15", "16", "17", "18","19", "20", "21",
 "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32",
 "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43",
 "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54",
 "55", "56" ,"57" ,"58", "59", "60", "61", "62", "62", "63", "64",
 "65","66", "67", "68", "69", "70", "71", "72", "73", "74", "75", 
 "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86",
 "87", "87", "89", "90", "91", "92", "93", "94", "95", "96", "97",
 "98", "99"};

static const int MaxDaysInMonth[] =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//prototype for juliandays (without leap year)
int julianDays(int m, int d);

Date :: Date()
{
	//make the numbers constantsin the header file
	//these are the private values
	month = DEFAULTMONTH;
	day = DEFAULTDAY;
	year = DEFAULTYEAR;
	format = DEFAULTFORMAT;
}

Date :: Date(const int MONTH, const int DAY, const int YEAR)
{
	format = DEFAULTFORMAT;

	//Error checks the month, date, and year.
	if(Set(MONTH, DAY, YEAR)==false)
	{
		month = DEFAULTMONTH;
		day = DEFAULTDAY;
		year = DEFAULTYEAR;
		
	}

}

// *****************************************************************
// * Function Name: GetMonth *
// * Description: Gets month from constructor
// * Parameter Description: Passes an int variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
int Date :: GetMonth()
{
	return month;
}

// *****************************************************************
// * Function Name: GetDay *
// * Description: Gets day from constructor
// * Parameter Description: Passes an int variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
int Date :: GetDay()
{
	return day;
}
// *****************************************************************
// * Function Name: GetYear *
// * Description: Gets year from constructor
// * Parameter Description: Passes an int variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
int Date :: GetYear()
{
	return year;
}
// *****************************************************************
// * Function Name: Input *
// * Description: Takes input from user to change date values, calls
// * error checking function below
// * Parameter Description: void
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Date :: Input()
{
	int m, d, y;
	char ch1, ch2;

	bool flag;

	do
	{		
		flag = false;
	
		//Grabs data values
		cout << "Please enter the date in the format: month/date/year.";
		cin >> m >> ch1 >> d >> ch2 >> y;
		if(!Set(m, d, y))
		{flag = true;}
	}
	while(flag);
}
// *****************************************************************
// * Function Name: Show *
// * Description: Prints out the date in the described formats
// * Parameter Description:  void
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Date :: Show()
{
	if(format == 'D')//prints out date in default format
		{
			cout << month << "/" << day << "/" << year << endl;
		}
	else if(format == 'T')//prints out date in Two-Diget format
		{
			cout << "The Two-Digit date is: " << TWODIGETNUMBERS[month]<<'/'<<
			TWODIGETNUMBERS[day] << '/' << TWODIGETNUMBERS[(year+1)%100]<<endl;
		}
	
	else if(format == 'L')//prints out date in Long format
		{
			cout << ListOfMonths[month]<< ' ' << day << ", " << year << endl;
		}
	else if (format == 'J')//prints out date in Julian format
		{
			cout << TWODIGETNUMBERS[(year)%100] << '-';

			if(julianDays(month, day) < 10)
			{
				cout << "00" << julianDays(month, day)<<endl;
			}

			else if(julianDays(month, day) < 100 && julianDays(month, day)>10)
			{
				cout << "0" << julianDays(month, day)<<endl;
			}

			else
			{
				cout << julianDays(month, day)<<endl;
			}
		}
	else
		cout << "Format is not a recognizable value.";

}

// *****************************************************************
// * Function Name: IncrementByOne *
// * Description: calculates correct day with regard to month/year overflow
// * Parameter Description: void
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Date::IncrementByOne()
{
	//create temporary value to use in this function
	int tempDay = day+1;

	//calculation fot going to the next month
	if (tempDay > MaxDaysInMonth[month])
	{
		day = 1;
		month = month+1;
	}
	else
		day = tempDay;

	//calculation for going to the next year
	if (month > 12)
	{
		month = 1;
		day = 1;
		year++;
	}
}

// *****************************************************************
// * Function Name: Increment *
// * Description: Gets month from constructor
// * Parameter Description: Passes an int variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
void Date :: Increment(int _numDays)
{
	//calls the IncrementByOne function as many times as needed
	for (int i = 0; i<_numDays; i++)
		IncrementByOne();
}
// *****************************************************************
// * Function Name: Compare *
// * Description: Compares the dates and returns corresponding value
// * Parameter Description: Passes a reference value
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
int Date :: Compare(const Date& d)
{
	int call, parameter;

	call = month + day + year;

	parameter = d.month + d.day + d.year; 

	if (call < parameter)
		return -1;
	else if (parameter < call)
		return 1;
	else 
		return 0;


	return 0;
}
// *****************************************************************
// * Function Name: GetMonth *
// * Description: Assigns format to the date
// * Parameter Description: Passes an char variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool Date :: SetFormat(char f)
{

	if(f == 'D')
	{
		format = f;
		return true;
	}
	else if(f == 'T')
	{
		format = f;
		return true;
	}
	else if(f == 'L')
	{
		format = f;
		return true;
	}
	else if(f == 'J')
	{
		format = f;
		return true;
	}
	else
	{
		cout << "Invalid format.";
		return false;
	}
}

// *****************************************************************
// * Function Name: Set *
// * Description: Error checks date values, turns them into defaults if needed
// * Parameter Description: Passes 3 int variables
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
bool Date :: Set(int m, int d, int y)
{

	if (y <0)
	{
		cout << "Please enter a valid year.";
		return false;
	}
	else if (m > 13 || m <0)
	{
		cout << "Please enter a valid month.";
		return false;
	}
	else if (d < 0 || d > MaxDaysInMonth[m])
	{
		cout << "Please enter a valid day.";
		return false;
	}
	else//everything checks out, assign the values
	{
		month=m;
		day=d;
		year=y;
		return true;
	}
}

// *****************************************************************
// * Function Name: ostream& *
// * Description: overloads the << operator to cout a date class
// * Parameter Description: passes reference values
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
ostream& operator << (ostream& newout, const Date& d)
{
	if(d.format == 'D')
			newout << d.month << "/" << d.day << "/" << d.year << endl;

	else if(d.format == 'T')
		{
			newout << TWODIGETNUMBERS[d.month] << '/' <<
			TWODIGETNUMBERS[d.day] << '/' <<
			TWODIGETNUMBERS[(d.year+1)%100] << endl;
		}
	
	else if(d.format == 'L')
		{
		newout << ListOfMonths[d.month]<< ' ' 
			   << d.day << ", " << d.year << endl;
		}
	else if (d.format == 'J')
		{
			newout << TWODIGETNUMBERS[(d.year)%100] << '-';

			if(julianDays(d.month, d.day) < 10)
			{
				newout << "00" << julianDays(d.month, d.day)<<endl;
			}

			else if(julianDays(d.month, d.day) < 100 && julianDays(d.month, d.day)>10)
			{
				newout << "0" << julianDays(d.month, d.day)<<endl;
			}

			else
			{
				newout << julianDays(d.month, d.day)<<endl;
			}
	}
	else
		newout << "Format is not a recognizable value.";

	return newout;
}

// *****************************************************************
// * Function Name: julianDays *
// * Description:Calculates dates in Julian Days(does not account for leapyear)
// * Parameter Description: Passes an int variable
// * Date: 02/01/2013 Date of function modification) */
// * Author: Nicholas Castelli*
// *****************************************************************
int julianDays(int m, int d)// not counting for leapyear
{
	int julianDays = 0;

	for(int i = 1; i < m; i++)
	{
		julianDays += MaxDaysInMonth[i];
	}

	for(int i = 1; i <= d; i++)
	{
		julianDays++;
	}

	return julianDays;
}


