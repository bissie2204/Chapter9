// Part_7_Program_3.cpp
// Abigail Tamburello
// Languages and Paradigms
// Write a program that initializes a matrix called quantity that is initialized with : 
// Row 0: 2, 4,  3, 6, 9
// Row 1: 5, 8, 9, 3, 7
// Row 2: 1, 4, 3, 2, 10
// Write a function that takes the matrix, rows, columns and row number then reverse that row number in the matrix.
// For example, call the function: reverse(quantity, 3, 5, 1), so the function reverse is called 
// with the matrix quantity, number of rows = 3, number of columns = 5 and row number = 1 to
// reverse only that specific row.

#include <iostream>
using namespace std;

void reverseRow(int matrix[][5], int rows, int cols, int rowNum);

int main() {
    // Initialize the matrix
    int quantity[3][5] = {
        {2, 4, 3, 6, 9},
        {5, 8, 9, 3, 7},
        {1, 4, 3, 2, 10}
    };
    reverseRow(quantity, 3, 5, 1);

    // Display updated matrix
    cout << "Updated Matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << quantity[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// reverseRow function definition
// Uses two-pointer technique to reverse the specified row in place
void reverseRow(int matrix[][5], int rows, int cols, int rowNum) {
    if (rowNum < 0 || rowNum >= rows) {
        cout << "Invalid row number." << endl;
        return;
    }
    
    int left = 0;
    int right = cols - 1;

    while (left < right) {
        // Swap elements at left and right pointers
        int temp = matrix[rowNum][left];
        matrix[rowNum][left] = matrix[rowNum][right];
        matrix[rowNum][right] = temp;

        // Move pointers towards the center
        left++;
        right--;
    }
}