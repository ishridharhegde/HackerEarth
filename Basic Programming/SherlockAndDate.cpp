/*
	Problem link -> https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/sherlock-and-date/?layout=old
	Watson gives a date to Sherlock and asks him what is the date on the previous day. Help Sherlock. 
	You are given date in DD MM YYYY format. DD is an integer without leading zeroes. 
	MM is one of the "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" and "December" (all quotes for clarity).
	YYYY is also an integer between 1600 and 2000 without leading zeroes. You have to print the date of the previous day in same format.
	
	
	Input and Output
	First line, T (≤ 100), the number of testcases. Each testcase consists of date in specified format. 
	For each testcase, print the required answer in one line. Given date will be a valid date.
	
	SAMPLE INPUT 
	3
	23 July 1914
	2 August 2000
	5 November 1999
	
	SAMPLE OUTPUT 
	22 July 1914
	1 August 2000
	4 November 1999
*/

#include<iostream>
using namespace std;

bool isLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
   else
		return false;
}

void printPreviousDay(int day, string month, int year)
{
    string MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(day==1)
    {
        if(month == "January")
        {
            year--;
            cout<<"31 December"<<year<<"\n";
        }
        else
        {
            int monthFinder;
            for(int i=0; i<12; i++)
                if(month == MONTHS[i])
                {
                    monthFinder = i;
                    break;
                }
            monthFinder--;
            int newDay = DAYS[monthFinder];
            if(isLeapYear(year) && month == "March")
                newDay++;
            cout<<newDay<<" "<<MONTHS[monthFinder]<<" "<<year<<"\n";
        }
    }
    else
    {
        day--;
        cout<<day<<" "<<month<<" "<<year<<"\n";
    }
}


int main()
{
	int T;
	cin>>T;

	for(int i=0; i<T; i++)
	{
		int day,year; string month;
		cin>>day>>month>>year;
        printPreviousDay(day,month,year);
	}
}