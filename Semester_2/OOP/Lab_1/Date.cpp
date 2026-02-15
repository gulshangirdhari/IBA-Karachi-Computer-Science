#include <iostream>
#include <string>
using namespace std;
// class
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) {
        if(!(month > 0 && month < 13)) {
            this->month = 1;
        } else {
            this->month = month;
        }
        this->day = day;
        this->year = year;
    }

    // setters and getters
    // day
    void setDay(int day) {
        if(day>0 && day < 32)
            this->day = day;
        else 
            this->day = 1;
    }
    int getDay() {
        return this->day;
    }

    // month
    void setMonth(int month) {
        if(!(month > 0 && month < 13)) {
            this->month = 1;
        } else {
            this->month = month;
        }
    }
    int getMonth() {
        return month;
    }
    // year
    void setYear(int year){
        this->year = year;
    }
    int getYear() {
        return this->year;
    }

    // methods
    std::string formatDate() {
        std::string str = std::to_string(day) + "/" + std::to_string(month) +  "/" + std::to_string(year);
        return str;
    }
};

// main function
int main() {
Date d1(19, 1, 2024);
cout << d1.formatDate() << endl; // should print 19/1/2024
d1.setDay(17);
cout << d1.formatDate() << endl; // should print 17/1/2024
d1.setMonth(5);
cout << d1.formatDate() << endl; // should print 17/5/2024
Date d2(29, 13, 2024); // should set month to 1
cout << d2.formatDate() << endl; // should print 29/1/2024
return 0;
}
