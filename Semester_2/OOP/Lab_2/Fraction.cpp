#include <iostream>
using namespace std;

class Fraction {
private:
    int* num;
    int* den;

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    void reduce() {
        int g = gcd(*num, *den);
        *num /= g;
        *den /= g;
        if (*den < 0) {
            *num = -(*num);
            *den = -(*den);
        }
    }


public:
    // Default constructor
    Fraction() {
        num = new int(0);
        den  = new int(1);
    }

    // Parameterized constructor (no initializer list, ternary validation)
    Fraction(int n, int d) {
        num = new int(n);
        den = new int((d == 0) ? 1 : d);  // avoid division by zero
        reduce();
    }

    // copy  constructor (deep copy)
    Fraction(const Fraction& other) {
        num = new int(*other.num);
        den = new int(*other.den);
        reduce();
    }

    // setters
    void set_num(int n) {
        *num = n;
        reduce();
    }
    void set_den(int d) {
        *den = (d==0) ? 1 : d;
        reduce();
    }

    // getters
    int get_num() const{
        return *num;
    }
    int get_den() const{
        return *den;
    }
    // destructor
    ~Fraction() {
        if (num != nullptr) {
            delete num;
            num = nullptr;
        }
        if (den != nullptr) {
            delete den;
            den = nullptr;
        }
    }


    // copy assignment operator
    Fraction&operator=(const Fraction& other) {
        // self check 
        if(this == &other) return *this; 

        delete num;
        delete den;

        num = new int(*other.num);
        den = new int(*other.den);

        return *this;
    }
    // OR
    // Fraction& operator=(const Fraction& other) {
    //     if (this == &other) return *this;

    //     *num = *other.num;
    //     *den = *other.den;

    //     return *this;
    // }

    // Fraction + Fraction
    Fraction operator+(const Fraction& other) const {
        // int n = *num * *other.den + *other.num * *den;
        // int d = *den * *other.den;
        //return Fraction(n, d);
        return Fraction(*num * *other.den + *other.num * *den, *den * *other.den);
    }
       // Fraction - Fraction
    Fraction operator-(const Fraction& other) const {
        // int n = *num * *other.den - *other.num * *den;
        // int d = *den * *other.den;
        //return Fraction(n, d);
        return Fraction(*num * *other.den - *other.num * *den, *den * *other.den);
    }

    // Fraction * Fraction
    Fraction operator*(const Fraction& other) const {
        // int n = *num * *other.num;
        // int d = *den * *other.den;
        // return Fraction(n, d);
        return Fraction(*num * *other.num, *den * *other.den);
    }

    // Fraction / Fraction
    Fraction operator/(const Fraction& other) const {
        // int n = *num * *other.den;
        // int d = *den * *other.num;
        // return Fraction(n, d);
        return Fraction(*num * *other.den, *den * *other.num);
    }
    // equality operator
    // bool operator==(const Fraction& other) const {
    //     return (*num) * (*other.den) == (*other.num) * (*den);
    // }
     // OR
    bool operator==(const Fraction& other) const {
        // Make temporary copies so we can reduce them
        Fraction f1(*this);
        Fraction f2(other);

        f1.reduce();
        f2.reduce();

        return (*f1.num == *f2.num) && (*f1.den == *f2.den);
    }
    // inequality operator
    bool operator!=(const Fraction& other) const {
        return !(*this==other);
    }

    // // less than operator
    // bool operator<(const Fraction& other) const {
    //     if(((*num)* (*other.den)) < ((*den) * (*other.num))) {
    //         return true;
    //     }
    //     return false;
    // }
    //OR
    bool operator<(const Fraction& other) const {
        return (((*num)* (*other.den)) < ((*den) * (*other.num)));
    }
    // greater than operator 
    bool operator>(const Fraction& other) const {
        return (((*num)* (*other.den)) > ((*den) * (*other.num)));
    }

    // print 
    void print() const {
        std::cout << *num << "/" << *den << std::endl;
    }

    //double to_decimal
    double to_decimal() const {
        return (double) (*num)/ (*den);
    }
};

int main() {
    Fraction f1(1, 2);   // 1/2
    Fraction f2(1, 3);   // 1/3
    Fraction f3(2, 4);   // 2/4 -> should reduce to 1/2

    std::cout << "Test1: Copy Constructor" << std::endl;
    Fraction f4 = f1;
    std::cout << "f4 = ";
    f4.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test2: Assignment Operator" << std::endl;
    Fraction f5;
    f5 = f2;
    std::cout << "f5 = ";
    f5.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test3: Arithmetic Operators" << std::endl;
    Fraction sum = f1 + f2;
    std::cout << "1/2 + 1/3 = ";
    sum.print();
    std::cout << std::endl;

    Fraction diff = f1 - f2;
    std::cout << "1/2 - 1/3 = ";
    diff.print();
    std::cout << std::endl;

    Fraction prod = f1 * f2;
    std::cout << "1/2 * 1/3 = ";
    prod.print();
    std::cout << std::endl;

    Fraction quot = f1 / f2;
    std::cout << "1/2 / 1/3 = ";
    quot.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test4: Comparison Operators" << std::endl;
    if (f1 == f3) {
        std::cout << "1/2 and 2/4 are equal (after reduction)" << std::endl;
    }

    if (f2 < f1) {
        std::cout << "1/3 is less than 1/2" << std::endl;
    }

    if (f1 > f2) {
        std::cout << "1/2 is greater than 1/3" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Test5: Complex Expressions" << std::endl;
    Fraction f6(1, 4);
    Fraction result1 = f1 + f2 * f6;
    std::cout << "1/2 + (1/3 * 1/4) = ";
    result1.print();
    std::cout << std::endl;

    Fraction result2 = f1 * f2 + f6;
    std::cout << "(1/2 * 1/3) + 1/4 = ";
    result2.print();
    std::cout << std::endl << std::endl;

    std::cout << "Test6: Decimal Conversion" << std::endl;
    std::cout << "1/2 as decimal: " << f1.to_decimal() << std::endl;
    std::cout << "1/3 as decimal: " << f2.to_decimal() << std::endl;
    std::cout << std::endl;

    std::cout << "Test7: Setters and Getters" << std::endl;
    Fraction f7(6, 8);
    std::cout << "f7 before set: ";
    f7.print();
    std::cout << std::endl;
    f7.set_num(1);
    std::cout << "After set_num(1): ";
    f7.print();
    std::cout << std::endl;

    return 0;
}