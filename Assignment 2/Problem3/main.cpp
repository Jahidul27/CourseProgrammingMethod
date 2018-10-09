//Problem 3
// C++ program for 3-way quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

//THIS PART IS WHAT WOULD RANDOMIZE THE ARRAY
//void randomize ( int a[], int n )
//{
//    // Use a different seed value so that we don't get same
//    // result each time we run this program
//    srand ( time(NULL) );
//
//    // Start from the last element and swap one by one. We don't
//    // need to run for the first element that's why i > 0
//    for (int i = n-1; i > 0; i--)
//    {
//        // Pick a random index from 0 to i
//        int j = rand() % (i+1);
//
//        // Swap arr[i] with the element at random index
//        swap(&a[i], &a[j]);
//    }
//}
//END OF RANDOMIZATION

//Begin to partition the integers given in order to set up the sort. This will be the sorting portion
void LinkedList(int a[], int left, int right, int &i, int &j)
{
    i = left-1, j = right;
    int p = left-1, q = right;
    int x = a[right];

    while (true)
    {
        // Observing it from the left, we can find the first element greater than
        // or equal to x
        while (a[++i] < x);

        // If we look at it from the right we can find the first element smaller than or equal to x

        while (x < a[--j])
            if (j == left)
                break;

        // In this situation if we get that i and j cross, then we are done
        if (i >= j) break;

        // This is the main part of the whole problem where swapping occurs
        // so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // This will move all same left occurrence of pivot to beginning of the
        // array and also keep count using p
        if (a[i] == x)
        {
            p++;
            swap(a[p], a[i]);
        }

        // This provides the means to move all same right occurrence of pivot to the end of array
        // and then we can also keep count using q
        if (a[j] == x)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // This will proceed to move the pivot element to its correct index
    swap(a[i], a[right]);

    // Now we will Move all the left same occurrences that are from  the beginning
    // to teh adjacent to arr[i]
    j = i-1;
    for (int k = left; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i+1;
    for (int k = right-1; k > q; k--, i++)
        swap(a[i], a[k]);
}

//add an integer to the list
void add(int a);

// This is where the 3-way partition based quick sort happens
void quicksort(int a[], int left, int right)
{
    if (right <= left) return;

    int i, j;

    LinkedList(a, left, right, i, j);

    quicksort(a, left, j);
    quicksort(a, i, right);
}

// This is the print function to print the array
void printarr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d  ", a[i]);
    printf("\n");
}








// This is the main function to be manipulated.
int main()
{
    int a[] = {2, 3, 5, 7, 6, 7, 8};
    int size = sizeof(a) / sizeof(int);
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
} 