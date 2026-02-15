#include <iostream>
using namespace std;
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Friend function declaration
    friend Complex add(const Complex& c1, const Complex& c2);
    friend void display(const Complex& c);
 };
    // Friend function definition (outside the class)
Complex add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void display(const Complex& c) {
    cout << c.real << " + " << c.imag << "i" << endl;
}

int main() {
    Complex c1(23.0, 23), c2(23.5, 25);
    display(c1);
    cout << endl;
    display(c2); 
    cout << endl;
    Complex c3 = add(c2, c1);
    display(c3);


}