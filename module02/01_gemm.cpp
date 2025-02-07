/*
1. Matrix Multiplication using Functions

   Write a program that:
   - Implements a function `void multiplyMatrices(const vector<vector<int>> &mat1, 
    const vector<vector<int>> &mat2, vector<vector<int>> &result)` 
    that multiplies two matrices and stores the result in the result matrix (passed by reference).
   - Ensure that matrix multiplication is only performed if the dimensions allow it 
   (i.e., the number of columns in `mat1` equals the number of rows in `mat2`).
   - Validate dimensions inside the function and handle any incompatible cases.
*/

#include <iostream>
#include <vector>

using namespace std;

void multiplyMatrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &result) {
  // check the col shape of mat1
  auto mat1_row = mat1.size();
  auto mat1_col = mat1.at(0).size();
  // check the row shape of mat2
  //
  auto mat2_row = mat2.size();
  auto mat2_col = mat2.at(0).size();
  // check the 

  if (mat1_col == 0 || mat2_row == 0) {
    cout << "The matrix 1 has zero elements" << endl;
    return ;
  } else if (mat1_col != mat2_row) {
    cout << "The matrix 1 and Matrix 2 have wrong shapes" << endl;
    return ;
  }
  //

  for (auto i= 0; i < mat1_row; i++) {
    for (auto j= 0; i < mat2_col; j++) {
      int res_tmp = 0;
      for (auto k=0; k < mat1_col; k++) {
        res_tmp += mat1[i][k] * mat2[k][j];
      }
      // could I use this notation?  result.at(i).at(j) = res_tmp;
      result[i][j] = res_tmp;
    }
  } 
  return ;
}

/*
$ g++ -Wall -Wextra -c 01_gemm.cpp -std=c++14
01_gemm.cpp: In function 'void multiplyMatrices(const std::vector<std::vector<int> >&, const std::vector<std::vector<int> >&, std::vector<std::vector<int> >&)':        
01_gemm.cpp:37:21: warning: comparison of integer expressions of different signedness: 'int' and 'long long unsigned int' [-Wsign-compare]
   37 |   for (auto i= 0; i < mat1_row; i++) {
      |                   ~~^~~~~~~~~~
01_gemm.cpp:38:23: warning: comparison of integer expressions of different signedness: 'int' and 'long long unsigned int' [-Wsign-compare]
   38 |     for (auto j= 0; i < mat2_col; j++) {
      |                     ~~^~~~~~~~~~
01_gemm.cpp:40:25: warning: comparison of integer expressions of different signedness: 'int' and 'long long unsigned int' [-Wsign-compare]
   40 |       for (auto k= 0; k < mat1_col; k++) {
      |                       ~~^~~~~~~~~~
*/