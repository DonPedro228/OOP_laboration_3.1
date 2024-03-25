#include "Date.h"
using namespace std;

int main() {
    Date date;
    cin >> date;
    cout << date;
    ++date;
    cout << "Date after increment field: " << date << endl;

    Date date_2 = date + 10;
    cout << "Future date after adding 10 days: " << string(date_2) << endl;
    return 0;
}