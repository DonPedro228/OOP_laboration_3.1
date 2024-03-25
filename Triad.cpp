#include "Triad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

Triad::Triad()
{
	date[0] = 0;
	date[1] = 0;
	date[2] = 0;
}

Triad::Triad(int day, int month, int year)
{
	date[0] = day;
	date[1] = month;
	date[2] = year;
}

Triad::Triad(const Triad& other)
{
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
}

Triad& Triad::operator = (const Triad& other)
{
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
	return *this;
}

Triad& Triad::operator ++()
{
	++date[0];
	++date[1];
	++date[2];
	return *this;
}

Triad& Triad::operator --()
{
	--date[0];
	--date[1];
	--date[2];
	return *this;
}

int Triad::getDay() const {
	return date[0];
}

int Triad::getMonth() const {
	return date[1];
}

int Triad::getYear() const {
	return date[2];
}

void Triad::setDay(int day) {
	date[0] = day;
}

void Triad::setMonth(int month) {
	date[1] = month;
}

void Triad::setYear(int year) {
	date[2] = year;
}

Triad::operator string()const
{
	stringstream ss;
	ss << endl;
	ss << "Date: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
	return ss.str();
}

ostream& operator << (ostream& out, const Triad& m)
{
	out << string(m);
	return out;
}

istream& operator >> (istream& in, Triad& m)
{
	int day, month, year;
	cout << endl;
	cout << "Input date: ";
	in >> m.date[0] >> m.date[1] >> m.date[2];
	return in;
}

Triad::~Triad() {}