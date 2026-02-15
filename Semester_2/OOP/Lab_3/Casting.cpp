#include <iostream>
class Fraction {
    private: 
        int numerator, denominator;
    public: 
        Fraction(int n , int d) : numerator(n), denominator(d){}


    // conversion to double 
    operator double() const {
        return (double)numerator/denominator;
    }

    // conversion to int
    operator int() const {
        return numerator / denominator;
    }
};
int main() {
    Fraction f(3, 4);
    double d = f; // calls operator double()
    int i = f; // calls operator int()
    std::cout << d << std::endl; 
    std::cout << i << std::endl;
}