#include <iostream>
class Time {
private:
    int* hours;
    int* minutes;
    
    void normalize() {
        if (*minutes >= 60) {
            *hours += *minutes / 60;
            *minutes %= 60;
        }

        if (*minutes < 0) {
            *hours -= (*minutes - 59) / 60; // Adjust hours for negative minutes
            *minutes = (*minutes % 60 + 60) % 60; // Ensure minutes are positive
        }
    }

public:
    // constructor
    Time(int h = 0, int m = 0) {
        hours = new int(h);
        minutes = new int(m);
        normalize();
    }
    
    // copy constructor
    Time(const Time& other) {
        hours = new int(*other.hours);
        minutes = new int(*other.minutes);
    }
    // Destructor
    ~Time() {
        delete hours;
        delete minutes;
    }

    // Assignment operator
    Time& operator=(const Time& other) {
        if (this != &other) {
            delete hours;
            delete minutes;
            hours = new int(*other.hours);
            minutes = new int(*other.minutes);
        }
        return *this;
    }

    // Arithmetic operators
    Time operator+(const Time& other) const {
        int totalHours = *hours + *other.hours;
        int totalMinutes = *minutes + *other.minutes;
        return Time(totalHours, totalMinutes);
    }
    Time operator-(const Time& other) const {
        int totalHours = *hours - *other.hours;
        int totalMinutes = *minutes - *other.minutes;
        return Time(totalHours, totalMinutes);
    }
    Time operator*(int factor) const {
        // multiply time
        int totalHours = *hours * factor;
        int totalMinutes = *minutes * factor;
        return Time(totalHours, totalMinutes);
    }
    Time operator/(int divisor) const {
        // divide time
        int totalMinutes = getTotalMinutes() / divisor;
        int totalHours = totalMinutes / 60;
        totalMinutes = totalMinutes % 60;
        return Time(totalHours, totalMinutes);
    }

    // comparison operators
    bool operator==(const Time& other) const {
        return (*hours == *other.hours && *minutes == *other.minutes);
    }
    bool operator>(const Time& other) const {
        if (*hours > *other.hours) return true;
        if (*hours < *other.hours) return false;
        return *minutes > *other.minutes;
    }
    bool operator<(const Time& other) const {
        return !(*this > other) && !(*this == other);
    }

    // UTILITY METHODS
    int getTotalMinutes() const {
        return (60*(*hours)) + (*minutes);
    }
    double getTotalHours() const {
        // decimal hours
        return (double)getTotalMinutes() / 60.0;
    }
    void display() const {
        std::cout << *hours << " hours and " << *minutes << " minutes";
    }
};

int main() {
    Time t1(2, 45);
    Time t2(1, 30);
    Time t3(0, 150); // Should normalize to 2h 30m
    std::cout << "Time 1: "; t1.display();
    std::cout << "Time 2: "; t2.display();
    std::cout << "Time 3 (after normalization): "; t3.display();
    // Arithmetic operations
    Time sum = t1 + t2;
    Time diff = t1- t2;
    Time doubled = t1 * 2;
    Time halved = t1 / 2;
    std::cout << "\nSum: "; sum.display();
    std::cout << "Difference: "; diff.display();
    std::cout << "Doubled: "; doubled.display();
    std::cout << "Halved: "; halved.display();
    // Utility methods
    std::cout << "\nTotal minutes in t1: " << t1.getTotalMinutes() << std::endl;
    std::cout << "Total hours in t1 (decimal): " << t1.getTotalHours() << std::endl;
    // Comparison operators
    if (t1 > t2) {
    std::cout << "\nt1 is greater than t2" << std::endl;
    }
    if (t1 == Time(2, 45)) {
    std::cout << "t1 equals 2h 45m" << std::endl;
    }

    // Test copy constructor
    std::cout << "\n--- Testing Copy Constructor---" << std::endl;
    Time t4 = t1;
    t4 = t4 + Time(1, 0); // Add 1 hour
    std::cout << "Original t1: "; t1.display();
    std::cout << "Modified copy t4: "; t4.display();
    // Test assignment operator
    std::cout << "\n--- Testing Assignment Operator---" << std::endl;
    Time t5(0, 0);
    t5 = t2;
    std::cout << "Assigned t5: "; t5.display();
    // Self-assignment
    t5 = t5;
    std::cout << "After self-assignment: "; t5.display();      
    return 0;
}