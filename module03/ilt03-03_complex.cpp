/*
3. Complex Number Class
   Create a Complex class to represent complex numbers with:
   - Real and imaginary parts stored as double.
   - Implement the rule of five:
     - A user-defined copy constructor.
     - A copy assignment operator.
     - A move constructor.
     - A move assignment operator.
     - A destructor.
   - Overload the following operators:
     1. Addition (+): Add two complex numbers.
     2. Subtraction (-): Subtract two complex numbers.
     3. Multiplication (*): Multiply two complex numbers.
     4. Assignment (=): Assign a complex number to another.
*/
#include <iostream>     // to use std::cout
#include <ostream>      // to use std::ostream

template <typename T>
class Complex {
  T real;        // Real part
  T imag;        // Imaginary part
  
  public:
    // Default constructor
    Complex() : real(0), imag(0) {
      std::cout << "Complex default constructor called" << std::endl;
    }
    // Parameterized constructor
    Complex(T real, T imag) : real(real), imag(imag) {
      std::cout << "Complex parameterized constructor called" << std::endl;
    }
    // Copy constructor
    Complex(const Complex& other) : real(other.real), imag(other.imag) {
      std::cout << "Complex copy constructor called" << std::endl;
    }
    // Copy assignment operator
    Complex& operator=(const Complex& other) {
      std::cout << "Complex copy assignment operator called" << std::endl;
      if (this != &other) {
        this->real = other.real;
        this->imag = other.imag;
      }
      return *this;
    } 
    // Move constructor
    Complex(Complex&& other) : real(std::move(other.real)), imag(std::move(other.imag)) {
      std::cout << "Complex move constructor called" << std::endl;
    }
    // Move assignment operator
    Complex& operator=(Complex&& other) {
      std::cout << "Complex move assignment operator called" << std::endl;
      if (this != &other) {
        this->real = std::move(other.real);
        this->imag = std::move(other.imag);
      }
      return *this;
    }
    // Destructor
    ~Complex() {
      std::cout << "Complex destructor called" << std::endl;
    }

    // Overload the + operator to add two complex numbers
    Complex& operator+(const Complex& other) {
        this->real += other.real;
        this->imag += other.imag;
        return *this;
    }

    // Overload the - operator to subtract two complex numbers
    Complex& operator-(const Complex& other) {
        this->real -= other.real; 
        this->imag -= other.imag;
        return *this;
    } 

    // Overload the * operator to multiply two complex numbers
    Complex& operator*(const Complex& other) {
        auto locreal = this->real * other.real - this->imag * other.imag;
        auto locimag = this->real * other.imag + this->imag * other.real;
        this->real = locreal;
        this->imag = locimag;
        return *this;
    } 
    // We do not need to overload operator = 
    // Overload the = operator to assign a complex number to another

    // Overload the << operator to print the complex number
    friend std::ostream& operator<<(std::ostream& os, const Complex& cnumber) {
        os << (cnumber.real) << " + " << cnumber.imag << "i";
        return os;
    }

};

int main() {
  Complex<double> c1(1.0, 2.0);
  Complex<double> c2(3.0, 4.0);
  std::cout << "c1: " << c1 << std::endl;
  std::cout << "c2: " << c2 << std::endl;
  Complex<double> c3 = c1 + c2;
  std::cout << "c3 = c1 + c2: " << c3 << std::endl;
  Complex<double> c4 = c1 - c2;
  std::cout << "c4 = c1 - c2: " << c4 << std::endl;
  Complex<double> c5 = c1 * c2;
  std::cout << "c5 = c1 * c2: " << c5 << std::endl;
  Complex<double> c11;
  c11 = c1; // Using copy assignment operator
  std::cout << "c11 = c1: " << c11 << std::endl;

  Complex<double> c12 = std::move(c2); // Using move constructor
  std::cout << "c12 = std::move(c2): " << c12 << std::endl;

  Complex<float> c6(1.5f, 2.5f);
  Complex<float> c7(3.5f, 4.5f);
  std::cout << "c6: " << c6 << std::endl;
  std::cout << "c7: " << c7 << std::endl;
  Complex<float> c8 = c6 + c7;
  std::cout << "c8 = c6 + c7: " << c8 << std::endl;
  Complex<float> c9 = c6 - c7;
  std::cout << "c9 = c6 - c7: " << c9 << std::endl;
  Complex<float> c10 = c6 * c7;
  std::cout << "c10 = c6 * c7: " << c10 << std::endl;
  return 0;
}
