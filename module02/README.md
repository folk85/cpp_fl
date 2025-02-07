## Module 2: Homework tasks

1. Matrix Multiplication using Functions

   Write a program that:
   - Implements a function `void multiplyMatrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &result)` that multiplies two matrices and stores the result in the result matrix (passed by reference).
   - Ensure that matrix multiplication is only performed if the dimensions allow it (i.e., the number of columns in `mat1` equals the number of rows in `mat2`).
   - Validate dimensions inside the function and handle any incompatible cases.
 
2. Merge Sort with Recursion and Pass by Reference

   Write a recursive function `void mergeSort(vector<int> &arr, int left, int right)` that:
   - Takes a vector of integers by reference.
   - Sorts the array using the Merge Sort algorithm.
   - Write a helper function `void merge(vector<int> &arr, int left, int mid, int right)` to merge two halves of the array.
   - Ensure that the array is passed by reference to avoid copying data.
 
3. Function Pointer for Custom Operations on Arrays

   Write a program that:
   - Defines three functions `add`, `multiply`, and `subtract` that operate on two integers.
   - Uses a function pointer to apply a selected operation (e.g., `addition`, `multiplication`, `subtraction`) to every element of two arrays of integers.
   - Create a function `void applyOperation(int arr1[], int arr2[], int result[], int n, int (op)(int, int))` that takes the two arrays, a result array, the number of elements, and a function pointer op to apply the selected operation to corresponding elements in the arrays.
 
4. Generate All Subsets (Power Set) using Recursion and Lambda

   Write a recursive function `void generateSubsets(vector<int> &set, vector<int> &current, int index, const function<void(const vector<int>&)> &callback)` that:
   - Generates all possible subsets (power set) of a given set of integers.
   - Uses a lambda function as a callback to process each subset (e.g., print, store).
   - Demonstrates the use of the lambda to print each subset to the console as it's generated.
 
5. Higher-Order Function for Custom Sorting

   Write a function `void customSort(vector<int> &arr, bool (compare)(int, int))` that:
   - Takes a comparison function pointer compare to perform custom sorting.
   - Write two comparison functions: `compareAsc` for ascending order and `compareDesc` for descending order.
   - Sort the array in `main()` by passing `compareAsc` and `compareDesc` function pointers to `customSort`, and demonstrate sorting both ways.
 
6. Find All Even Numbers in a Vector

   Write a program that:
   - Takes a vector of integers as input.
   - Uses the STL algorithm `std::copy_if` along with a lambda function to find and copy all even numbers to a new vector.
   - Prints the new vector of even numbers using `std::for_each` and a lambda to format the output.
 
 
7. Group Strings by Their Length
   Write a program that:
   - Takes a vector of strings as input.
   - Uses the STL algorithm `std::partition` with a lambda function to group strings by their length, separating strings with even lengths from those with odd lengths.
   - Use `std::sort` within each group (even and odd length strings) to further sort alphabetically.
   - Print the grouped and sorted strings using `std::for_each` and a lambda.
 
8. Find the Top K Frequent Elements
   Write a program that:
   - Takes a vector of integers and an integer K as input.
   - Uses a lambda function with the STL algorithm std::unordered_map to count the frequency of each element.
   - Uses std::partial_sort with a lambda function to find the top K most frequent elements in the vector.
   - Print the top K frequent elements.
 
 
9. Find Longest Consecutive Subsequence
   Write a program that:
   - Takes a vector of integers as input.
   - Uses std::set to store unique elements, and std::for_each with a lambda function to iterate through the set.
   - Identify the longest consecutive subsequence (i.e., a sequence of integers where each number follows the previous one consecutively, e.g., [1, 2, 3, 4]).
   - Print the length of the longest consecutive subsequence.
 
10. Efficient String Searching Using Lambda and STL

   Write a program that:
   - Takes a large vector of strings as input and a search string s.
   - Uses std::search and a lambda function to implement a custom string search algorithm that looks for the search string s within each string of the vector, but the match should ignore case sensitivity.
   - The lambda function should check each character of the strings in a case-insensitive manner.
   - Return and print all strings that contain the search string, ignoring case.


## ILT Session 

### Roadmap
Functions:
- f declaration and definition
- f overloading 
- generic programming
- f pointers
- lambdas

Constant declarations
- constant variables
- enums
- constexpr 

