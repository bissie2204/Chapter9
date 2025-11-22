// Part_7_Program_1.cpp
// Abigail Tamburello
// Languages and Paradigms
// Initialize an array stock that is initialized with
// stock prices for a share: 22.2, 22.7, 23.5, 22.8, 24.3, 25.6. 
// Write a function that takes an array and size as a parameter
// and returns the sum and average (mean) of the array. 

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Overloaded function: sum of array
double computeSum(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Generic function for average of array
template <typename T>
double computeAverage(const T arr[], int size) {
    if (size == 0) return 0.0; // Avoid division by zero
    double sum = computeSum(arr, size);
    return sum / size;
}

// Subprogram using parameter passing by reference
// Takes an array and size, returns sum and average by reference
void computeSumAndAverage(const double arr[], int size, double &sum, double &average) {
    sum = computeSum(arr, size);
    average = computeAverage(arr, size);
}

// Function as parameter
void applyToArray(const double arr[], int size, function<void(double)> func) {
    for (int i = 0; i < size; ++i) {
        func(arr[i]);
    }
}

int main() {
    const int SIZE = 6;
    double stock[SIZE] = {22.2, 22.7, 23.5, 22.8, 24.3, 25.6};

    double sum = 0.0;
    double average = 0.0;

    computeSumAndAverage(stock, SIZE, sum, average);

    cout << "Sum of stock prices: " << sum << endl;
    cout << "Average stock price: " << average << endl;

    // Example of using function as parameter to print each stock price
    cout << "Stock prices: ";
    applyToArray(stock, SIZE, [](double price) {
        cout << price << " ";
    });
    cout << endl;

    return 0;
}