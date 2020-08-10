#include<iostream> 
using namespace std; 
  
// A date has day 'd', month 'm' and year 'y' 
struct Date 
{ 
    int d, m, y; 
}; 
  
// To store number of days in all months from January to Dec. 
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
  
// This function counts number of leap years before the 
// given date 
int countLeapYears(Date d) 
{ 
    int years = d.y; 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.m <= 2) 
        years--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} 
  
// This function returns number of days between two given 
// dates 
int getDifference(Date dt1, Date dt2) 
{ 
    unsigned int n1 = dt1.y*365 + dt1.d; 
    unsigned int n2 = dt2.y*365 + dt2.d; 
    
    for (int i=0; i<dt1.m - 1; i++) 
        n1 += monthDays[i]; 
    n1 += countLeapYears(dt1); 
  
    
    for (int i=0; i<dt2.m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2); 

    return (n2 - n1); 
} 
  
// Driver program 
int main() 
{ 
    Date dt1 = {31, 12, 2019}; 
    Date dt2 = {1, 1, 2020}; 
  
    cout << "Difference between two dates is " << getDifference(dt1, dt2) << endl; 
	cout << countLeapYears(dt1) << endl;
	cout << countLeapYears(dt2) << endl;
    return 0; 
}
