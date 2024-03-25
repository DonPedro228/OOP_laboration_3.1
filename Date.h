#include "Triad.h"

class Date : public Triad
{
public:
    Date();
    Date(int day, int month, int year);
    Date(const Date& other);
    Date& operator=(const Date& other);
    Date& operator--();
    friend Date operator+(const Triad& date, int days);
    friend ostream& operator<<(ostream& out, const Date& m);
    friend istream& operator>>(istream& in, Date& m);
    operator string() const;
    ~Date(void);
};