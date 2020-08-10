#include <iostream>

using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31};  

class Date{
private:
	int day, month, year;
	
public:	
	Date(){
		day =7;
		month = 8;
		year = 2020;
	}
	Date(const Date& right){
		this->day = right.day;
		this->month = right.month;
		this->year = right.year;
	}
	Date(int day,int month ,int year){
		//required validation <not implement>
		this->day = day;
		this->month = month;
		this->year = year;
	}
	
	void print(){
		cout << "dd/mm/yyyy: " << day << " /" << month  <<" /" << year;  
	};
	
	//setter
	void setYear(int year){
		this->year = year;
	};
	void setMonth(int month){
		if (month >=1 && month <= 12) this->month = month;
		else throw string("month must between 1 and 12");
	};
	void setDay(int day){
		if (day < 1 && day > 31) throw string("day is invalid");
		if (month == 1 || month ==3 || month ==5|| month ==7||month ==8|| month ==10|| month ==12){
			 if (this->day >= 1 && this->day <= 31) this->day = day;
			 else throw string("day must between 1 and 31");
		}
		if (month == 4 || month == 6 || month == 9 || month == 11){
			if (this->day >= 1 && this->day <= 30) this->day = day;
			else throw string("day must between 1 and 30");
		}
		if (month == 2){ // haven't check leap year
			if (this->day >= 1 && this->day <= 29) this->day = day;
			else throw string("invalid day for month 2");
		}
	};
	//getter
	int getDay(){
		return day;
	};
	int getMonth(){
		return month;
	};
	int getYear(){
		return year;
	};	
	
	int compare(Date &right){
		if (this->year != right.year){
			throw string("year is not equal");
		}
		if (this->month != right.month){
			throw string("month is not equal");
		}
		if (this->day == right.day) return 0;
		if (this->day > right.day) return 1;
		if (this->day < right.day) return -1;			
	};
	
	int countLeapYears(Date d){ 
		int y = d.year; 

		if (d.month <= 2) 
			y--; 
			
		return y/4 - y/100 + y/400; 
	};
	
	int diff(Date &right){
		unsigned int count1 = year*365 + day;
		unsigned int count2 = right.year*365 + right.day;
		
		for (int i=0; i < (month - 1); i++) count1 += monthDays[i];
		 
		count1 += this->countLeapYears(*this);
		
		for (int i=0; i < (right.month - 1); i++) count2 += monthDays[i]; 
		count2 += right.countLeapYears(right);
		
		return (count2 - count1);
	};
};

int main(){
	cout << " Please uncomment section to run the test you want" << endl;
	//Date d;
	//Date d1 = {20,5,2020};
	//Date d2 = {21,5,2020};
	//Date d3 = {22,5,2020};
	
	//d.setDay(-1);
	//d.setMonth(8);
	//d.setYear(2020);
	//d.getDay();
	//d.getMonth();
	//d.getYear();
	//d.print();
	
	
	
	//copy constructor test
	/*
	Date d1(7,8,2020);
	Date d2 = d1;
	d1.print();
	cout << "****";
	d2.print();
	*/
	
	//compare test
	/*
	Date d1 = {7,8,2020};
	Date d2 = {6,8,2020};
	Date d3 = {7,8,2020};
	Date d4 = {9,8,2020};
	
	cout << d1.compare(d2) << endl; // out: 1 (d1>d2)
	cout << d1.compare(d3) << endl; // out: 0 (d1=d2)
	cout << d1.compare(d4) << endl; // out: -1 (d1<d2)
	*/
	
	//diff test
	/*
	Date d1 = {20,5,2019};
	Date d2 = {21,5,2020};
	
	cout << d1.diff(d2) << endl;
	*/
	cout << endl;
	return 0;
}



