//---------------------------------------------------------------------------

#ifndef idc_dateH
#define idc_dateH
//---------------------------------------------------------------------------
#endif
#include <iostream>

using namespace std;

struct Date {

	string date;

	Date(const char * date = "01/01/00");
	~Date();

	static Date TodayDate();

	friend ostream& operator<< (std::ostream &out, const Date &n);
	friend istream& operator>> (std::istream &in, Date &n);
	friend bool operator==(const Date& left, const char* right);
	friend bool operator==(const Date& left, Date & right);

	Date& operator=(const char* right);
};
