#include <iostream>
//class Temperature
class Temperature {
private: 
    double celsius;

public:
    // Constructor takes calcius value
    Temperature (double c = 0) : celsius(c) {}

    // casting operators
    operator double() const {
        return (double)celsius;
    }
    operator int() const {
        return (int) celsius;
       // return static_cast<int>(celsius) using static_cast keyword
    }

    // friend function to get Fahrenheit
    friend double toFahrenheit(const Temperature& t);
    
    void display() const {
        std::cout << "Temperature (in °C): "  << celsius << "°C"// alt + 0176 for ° symbol
                  << "\nTemperature (in °F): "  << toFahrenheit(*this) << "°F" << std::endl; // alt + 0176 for ° symbol
    }
};

// friend function definition 
double toFahrenheit (const Temperature& t) {
    return t.celsius*(double)9/5 +32;
}

// main function
int main() {
    Temperature t1(25.5);
    Temperature t2(100);
    Temperature t3(-40);
    t1.display();
    t2.display();
    t3.display();
    double c = t1; // Casting to double
    int ci = t1; // Casting to int
    std::cout << "Temperature in Celsius (double): " << c << std::endl;
    std::cout << "Temperature in Celsius (int): " << ci << std::endl;
    std::cout << "Temperature in Fahrenheit:" << toFahrenheit(t1) << std::endl;
    return 0;
}