/*
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
*/

#include <iostream>     // to use std::cout
#include <vector>       // add std sdt::vector

/// @brief Matrix class
class Matrix {
  int rows;               // Number of rows
  int cols;               // Number of columns
  std::vector<std::vector<int>> data; // Matrix data
  
  public:
  // Default constructor
  Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {
    std::cout << "Matrix constructor called" << std::endl;
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        this->data[i][j] = 0;
      }
    }
  }  

  // Copy constructor
  Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {
    std::cout << "Matrix copy constructor called" << std::endl;
  }
  // Move constructor
  Matrix(Matrix&& other) : rows(other.rows), cols(other.cols), data(std::move(other.data)) {
    std::cout << "Matrix move constructor called" << std::endl;
  }
  // Destructor
  ~Matrix() {
    std::cout << "Matrix destructor called" << std::endl;
  }
  // Copy assignment operator
  Matrix& operator=(const Matrix& other) {
    std::cout << "Matrix copy assignment operator called" << std::endl;
    if (this != &other) {
      this->rows = other.rows;
      this->cols = other.cols;
      this->data = other.data;
    }
    return *this;
  }
  // Move assignment operator
  Matrix& operator=(Matrix&& other) {
    std::cout << "Matrix move assignment operator called" << std::endl;
    if (this != &other) {
      this->rows = other.rows;
      this->cols = other.cols;
      this->data = std::move(other.data);
    }
    return *this;
  }
  // Print matrix information
  void print() const {
    std::cout << "Matrix: " << rows << " x " << cols;
    int minVal = this->data[0][0];
    int maxVal = this->data[0][0];
    bool hasNaN = false;

    for (const auto& row : this->data) {
      for (const auto& val : row) {
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
        if (val != val) hasNaN = true; // NaN check
      }
    }

    std::cout << ", Min Value: " << minVal << ", Max Value: " << maxVal;
    if (hasNaN) {
      std::cout << ", Contains NaN values";
    }
    std::cout << std::endl;

  }

  // Overload the addition operator
  Matrix& operator+(const Matrix& other) {
    if (this->rows != other.rows || this->cols != other.cols) {
      throw std::invalid_argument("Matrix dimensions are not compatible for addition");
    }
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        this->data[i][j] += other.data[i][j];
      }
    }
    return *this;
  }

  // Overload the multiplication operator
  Matrix operator*(const Matrix& other) const {
    if (this->cols != other.rows) {
      throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");
    }
    if (this->rows == 0 || this->cols == 0 || other.cols == 0) {
      throw std::invalid_argument("One of the matrices has zero rows or columns");
    }
    // create result mtx
    Matrix result(this->rows, other.cols);
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < other.cols; ++j) {
        for (int k = 0; k < this->cols; ++k) {
          result.data[i][j] += this->data[i][k] * other.data[k][j];
        }
      }
    }
    return result;
  }

  // comparison operator
  bool operator==(const Matrix& other) const {
    // check the shapes of the matrices
    if (this->rows != other.rows || this->cols != other.cols) {
      return false;
    }
    // check the values of the matrices
    for (int i = 0; i < this->rows; ++i) {
      for (int j = 0; j < this->cols; ++j) {
        if (this->data[i][j] != other.data[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  // friend function to overload the << operator
  friend std::ostream& operator<<(std::ostream& os, const Matrix& mtx) {
    for (int i = 0; i < mtx.rows; ++i) {
      for (int j = 0; j < mtx.cols; ++j) {
        os << mtx.data[i][j] << " ";
      }
      os << std::endl;
    }
    return os;
  }
};

int main() {
  Matrix mtx1(2, 3);
  mtx1.print();

  Matrix mtx2(2, 3);
  mtx2.print();

  Matrix mtx3 = mtx1 + mtx2;
  mtx3.print();

  Matrix mtx4(3, 2);
  mtx4.print();

  Matrix mtx5 = mtx1 * mtx4;
  mtx5.print();

  Matrix mtx6(2, 3);
  mtx6.print();

  std::cout << "Matrix 1 == Matrix 2: " << (mtx1 == mtx2) << std::endl;
  std::cout << "Matrix 1 == Matrix 6: " << (mtx1 == mtx6) << std::endl;

  std::cout << "Matrix 1:" << std::endl << mtx1;
  std::cout << "Matrix 2:" << std::endl << mtx2;
  std::cout << "Matrix 3 (Matrix 1 + Matrix 2):" << std::endl << mtx3;
  std::cout << "Matrix 4:" << std::endl << mtx4;
  std::cout << "Matrix 5 (Matrix 1 * Matrix 4):" << std::endl << mtx5;
  std::cout << "Matrix 6:" << std::endl << mtx6;

  return 0;
}