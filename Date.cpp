#include "Date.h"
#include <sstream>
using namespace std;

Date::Date() : Triad() {}

Date::Date(int day, int month, int year) : Triad(day, month, year) {}

Date::Date(const Date& other) : Triad(other) {}

Date& Date::operator--()
{
    Triad::operator--();
    return *this;
}

Date& Date::operator=(const Date& other)
{
    if (this != &other) {
        Triad::operator=(other);
    }
    return *this;
}

Date operator+(const Triad& date, int days)
{
    int day = date.getDay() + days;
    int month = date.getMonth();
    int year = date.getYear();

    while (day > 31 || (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day > 29) ||
        (month == 2 && ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) && day > 28) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day -= 29;
            }
            else {
                day -= 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            day -= 30;
        }
        else {
            day -= 31;
        }
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    return Date(day, month, year);
}


Date::operator string() const
{
    stringstream ss;
    ss << endl;
    ss << "Date: " << getDay() << "/" << getMonth() << "/" << getYear() << endl;
    return ss.str();
}

ostream& operator<<(ostream& out, const Date& m)
{
    out << static_cast<string>(m);
    return out;
}

istream& operator>>(istream& in, Date& m)
{
    int day, month, year;
    cout << endl;
    cout << "Input date: ";
    in >> day >> month >> year;
    m.setDay(day);
    m.setMonth(month);
    m.setYear(year);
    return in;
}


Date::~Date() {}