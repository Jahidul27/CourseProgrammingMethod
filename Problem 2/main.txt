#include <iostream>
using namespace std;

int size=10;
int* a   = new int[size];
int  n   = 0;

//This is for dynamic array expansion
int main() {
    while (cin >> a[n]) {
        n++;
        if (n >= size) {
            size = size * 2;            // This will Double the previous size of the array
            int *temp = new int[size]; // Now we can Allocate a newer and larger array
            for (int i = 0; i < n; i++) {
                temp[i] = a[i];       // We can copy the old array data to new array
            }
            delete[] a;              // Since we don't need the old array we can free old array memory
            a = temp;                 // We can use the variable a to now point to new array
        }
    }
}