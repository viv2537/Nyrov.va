//---------------------------------------------------------------------------

#pragma hdrstop

#include "idc_date.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <ctime>
#include <string>



Date::~Date()
{ };

Date::Date(const char * date = "01/01/00")
{

	this->date = "2000-00-00";
	int month = ((int)date[0] - '0') * 10 + (int)date[1] - '0';
	int day = ((int)date[3] - '0') * 10 + (int)date[4] - '0';
	int year = ((int)date[6] - '0') * 10 + (int)date[7] - '0' + 2000;


	//Ïîëó÷åíèå ãîäà
	for (int i = 2; i < 4; i++)
	{
		this->date[i] = date[i + 4];
	}


	//Ïîëó÷åíèå ìåñÿöà
	for (int i = 5; i < 7; i++)
	{
		this->date[i] = date[i - 5];
	}


	//Ïîëó÷åíèå äíÿ
	for (int i = 8; i < 10; i++)
	{
		this->date[i] = date[i - 5];
	}

	short NumberDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date[2] != '/' && date[5] != '/') std::cerr << "invalid date format, need mm/dd/yy " << '\n';
	else if (month > 12 || month == 0) std::cerr << "invalid month value. Must be 1 to 12.\nDate format is MM/DD/YY" << '\n';
	else if (day > NumberDays[month - 1]) std::cerr << "invalid day value. Must be 1 to 28-31" << '\n';
};

Date Date::TodayDate()
{

	//Ïîëó÷åíèå ñèñòåìíîãî âðåìåíè
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	int day = timeinfo->tm_mday;
	int month = timeinfo->tm_mon + 1;
	int year = timeinfo->tm_year + 1900;

	Date n;
	// Äàòà ôîðìàòà YYYY-MM-DD
	n.date = "0000-00-00";

	//Ââîä ãîäà
	for (int i = 0; i < 4; i++)
	{
		n.date[i] = (char)(year / (int)pow(10, 3 - i) % 10) + '0';
	}


	//Ââîä ìåñÿöà
	for (int i = 5; i < 7; i++)
	{
		n.date[i] = (char)(month / (int)pow(10, 6 - i) % 10) + '0';
	}


	//Ââîä äíÿ
	for (int i = 8; i < 10; i++)
	{
		n.date[i] = (char)(day / (int)pow(10, 9 - i) % 10) + '0';
	}
	return n;
}

Date& Date::operator=(const char* right)
{
	Date RDate(right);
	date = RDate.date;
	return *this;
}


ostream& operator<< (std::ostream &out, const Date &n)
{
	out << n.date;
	return out;
}


istream& operator>> (std::istream &in, Date &n)
{
	char t[9];
	in >> t;
	if (strlen(t) == 0);
	else if (strlen(t) != 8) std::cerr << "invalid date length, need 8 " << '\n';
	else if (t[2] != '/' && t[5] != '/') std::cerr << "invalid date format, need MM/DD/YY " << '\n';
	else
	{
		Date RDate(t);
		n.date = RDate.date;
	}
	return in;
}


bool operator==(const Date& left, const char* right)
{
	Date RDate(right);
	return left.date == RDate.date;
}


bool operator==(const Date& left, Date & right)
{
	return left.date == right.date;
}

//
