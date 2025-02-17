# CL-003 FL C++: ILT 3


1. Matrix Class
   Create a Matrix class that:
   - Supports dynamic 2D matrices (use vector<vector<int>> internally).
   - Overloads the following operators:
     1. Addition (+): Adds two matrices of the same dimension.
     2. Multiplication (*): Multiplies two matrices if their dimensions are compatible.
     3. Comparison (==): Compares two matrices for equality (element-wise).
   - Throw an exception if matrix dimensions are incompatible for addition or multiplication.
   - Add a friend function to overload the << operator to print the matrix.
   - Ensure matrix operations are optimized for large matrices, avoiding unnecessary deep copies.
 
2. Bank Account System
   Create a class hierarchy to represent a Bank Account system:
   - Base class Account should have:
     - Data members for account number, balance, and owner's name.
     - A virtual function void deposit(double amount) to increase balance.
     - A virtual function void withdraw(double amount) to decrease balance.
   - Derived class SavingsAccount should override withdraw() to restrict withdrawals if the balance falls below a minimum threshold.
   - Derived class CheckingAccount should override withdraw() to allow withdrawals but charge a fee if the balance falls below a certain limit.
   - Use polymorphism to manage different account types in a banking system.
   - Implement a system where transactions are logged, and each account tracks its own transaction history (e.g., store a list of transaction descriptions).
 
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
 
4. Multiple Inheritance
   Create a class structure that demonstrates the diamond problem:
   - Base class Person with a name and age.
   - Two derived classes:
     - Employee adds a job title and salary.
     - Student adds a degree.
   - A third class WorkingStudent inherits both Employee and Student.
   - Use virtual inheritance to ensure only one copy of Person is created in WorkingStudent.
   - Implement member functions to print details about a working student, including job and study details.
   - Ensure that WorkingStudent can access all Person, Employee, and Student data without ambiguity using virtual inheritance.
 
5. Smart Pointer-Like Class for Resource Management
   Create a custom class ResourceHolder that manages a resource, such as dynamic memory or a file handle:
   - Implement copy and move semantics:
     - A copy constructor that performs a deep copy of the resource.
     - A move constructor that transfers ownership of the resource, setting the original resource to nullptr.
     - Implement the copy assignment operator and move assignment operator.
   - Overload the dereference operator () and arrow operator (->) to access the resource.
   - Add a function to release the resource explicitly (optional).
   - Ensure proper resource cleanup in the destructor.
   - Manage an array of resources (e.g., dynamically allocated integers) using a custom smart pointer-like class and provide copy/move control for handling ownership efficiently.

