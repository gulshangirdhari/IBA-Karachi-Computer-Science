#include <iostream>
// class Distance
class Distance {
private: 
    double meters;

public:
    // constructor
    Distance (double m = 0) : meters(m) {}

    // Arithmetic operators
    Distance operator+(const Distance& other) const{
        return Distance(meters + other.meters);
    }
    Distance operator-(const Distance& other) const{ 
        return Distance((meters - other.meters) < 0 ? 0: (meters - other.meters));
    }
    Distance operator*(double factor) const {
        // Scale distance
        return Distance(meters * factor);
    }
   Distance operator/(double divisor) const {
        if (divisor == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return Distance(0);
        }
        return Distance(meters / divisor);
    }
    // Comparison operators
    bool operator>(const Distance& other) const {
        return (meters > other.meters);
    }
    bool operator<(const Distance& other) const {
        return (meters < other.meters);
    }
    bool operator==(const Distance& other) const {
        return (meters == other.meters);
    }
    // Casting operators
    operator double() const {
        // Returns meters
        return meters;
    } 
        
    operator int() const {
        // Returns centimeters (as int)
        return (int) (meters*100);
       // return static_cast<int> (meters*100);

    }

    // Utility methods
    double toFeet() const {
        // 1 meter = 3.28084 feet
        return 3.28084*meters;
    }
    double toInches() const {
        // 1 meter = 39.3701 inches
        return 39.3701*meters;
    }
    void display() const {
        std::cout << "========== Distance =========="
                  << "\nMeters: " << meters << "m"
                  << "\nFeet: " << toFeet() << "ft"
                  << "\nInches: " << toInches() <<"inches"
                  << "\nCM: " << 100*meters << "cm " << std::endl;
    }
};

// main function
int main() {
    Distance d1(5.5);
    Distance d2(3.2);
    Distance sum = d1 + d2;
    Distance diff = d1- d2;
    Distance scaled = d1 * 2;
    Distance halved = d1 / 2;
    std::cout << "Distance 1: "; d1.display();
    std::cout << "Distance 2: "; d2.display();
    std::cout << "Sum: "; sum.display();
    std::cout << "Difference: "; diff.display();
    std::cout << "Scaled (x2): "; scaled.display();
    std::cout << "Halved (/2): "; halved.display();
    // Casting operators
    double m = d1; // Casting to double (meters)
    int cm = d1;
    // Casting to int (centimeters)
    std::cout << "\nDistance in meters: " << m << std::endl;
    std::cout << "Distance in centimeters: " << cm << std::endl;
    std::cout << "Distance in feet: " << d1.toFeet() << std::endl;
    std::cout << "Distance in inches: " << d1.toInches() << std::endl;
    // Comparison
    if (d1 > d2) {
    std::cout << "\nd1 is greater than d2" << std::endl;
    }
    if (d1 == Distance(5.5)) {
    std::cout << "d1 equals 5.5 meters" << std::endl;
    }
    return 0;
}