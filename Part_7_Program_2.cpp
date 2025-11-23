// Part_7_Program_2.cpp
// Abigail Tamburello
// Languages and Paradigms
// Initialize an array called selling that is initialized with 
// sell prices for different months per year: 80, 50, 35, 65, 127, 77, 92, 85, 123, 90, 55, 124. 
// Write a function that takes an array and 
// size as a parameter and returns the largest, second largest and smallest elements.

#include <iostream>
#include <climits>
using namespace std;

void analyzeArray(const int arr[], int size, int &largest, int &secondLargest, int &smallest);

int main() {
    int selling[12] = {80, 50, 35, 65, 127, 77, 92, 85, 123, 90, 55, 124};
    int largest, secondLargest, smallest;
    analyzeArray(selling, 12, largest, secondLargest, smallest);

    // Output the results
    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;   
    cout << "Smallest: " << smallest << endl;

    return 0;
}

void analyzeSellingData(const int arr[], int size, int &largest, int &secondLargest, int &smallest) {
    // Initialize values
    largest = secondLargest = INT_MIN;
    smallest = INT_MAX;

    for (int i = 0; i < size; ++i) {
        int value = arr[i];
        if (value > largest) {
            secondLargest = largest; // Update second largest before updating largest
            largest = value;
        } else if (value > secondLargest && value != largest) {
            secondLargest = value;
        }
        if (value < smallest) {
            smallest = value;
        }
    }
}