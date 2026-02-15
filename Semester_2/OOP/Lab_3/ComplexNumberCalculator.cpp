#include <cmath>
#include <iostream>
// class complex
class Complex {
 private:
  double real;
  double imag;

 public:
  // constructor
  Complex(double r = 0, double i = 0) : real(r), imag(i) {}

  // Arithmetic operators
  Complex operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
  }
  Complex operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
  }
  Complex operator*(const Complex& other) const {
    return Complex((real * other.real) - (imag * other.imag),
                   (real * other.imag) + (imag * other.real));
  }

  // Casting operators
  operator double() const {
    // Returns magnitude
    return (double)std::sqrt((real * real) + (imag * imag));
  }

  operator int() const {
    // Returns real part as integer
    return real;
  }

  // Friend functions
  friend double magnitude(const Complex& c);
  friend void display(const Complex& c);
};

// definitions of friend functions
double magnitude(const Complex& c) {
  return std::sqrt((c.real * c.real) + (c.imag * c.imag));
}
void display(const Complex& c) {
    if (c.imag >= 0)
        std::cout << c.real << " + " << c.imag << "i" << std::endl;
    else
        std::cout << c.real << " - " << -c.imag << "i" << std::endl;
}

int main() {
  Complex c1(-3.9, 4.0);
  Complex c2(1.0, -2.7);
  Complex sum = c1 + c2;
  Complex diff = c1 - c2;
  Complex prod = c1 * c2;
  std::cout << "c1: ";
  display(c1);
  std::cout << "c2: ";
  display(c2);
  std::cout << "Sum: ";
  display(sum);
  std::cout << "Difference: ";
  display(diff);
  std::cout << "Product: ";
  display(prod);
  double mag = c1;  // Casting to double
  int r = c1;
  // Casting to int
  std::cout << "Magnitude of c1: " << mag << std::endl;
  std::cout << "Real part of c1 (as int): " << r << std::endl;
  std::cout << "Magnitude using friend: " << magnitude(c1) << std::endl;
  return 0;
}