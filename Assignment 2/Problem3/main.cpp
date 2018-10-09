
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

//Begin to partition in order to set up the sort
void partition(int a[], int l, int r, int &i, int &j)
{
    i = l-1, j = r;
    int p = l-1, q = r;
    int v = a[r];

    while (true)
    {
        // Observing it from the left, we can find the first element greater than
        // or equal to v. We can use this to have this loop that will definitely terminate
        // all because v is last element
        while (a[++i] < v);

        // If we look at it from the right we can find the first element smaller than or
        // equal to v 
        while (v < a[--j])
            if (j == l)
                break;

        // In this situation if we get that i and j cross, then we are done
        if (i >= j) break;

        // This is the main part of the whole problem where swapping occurs
        // so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // This will move all same left occurrence of pivot to beginning of the
        // array and also keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // This provides the means to move all same right occurrence of pivot to the end of array
        // and then we can also keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // This will proceed to move the pivot element to its correct index
    swap(a[i], a[r]);

    // Now we will Move all the left same occurrences that are from  the beginning
    // to teh adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}

//add an integer to the list
void add(int a);

// This is where the 3-way partition based quick sort happens
void quicksort(int a[], int l, int r)
{
    if (r <= l) return;

    int i, j;

    partition(a, l, r, i, j);

    quicksort(a, l, j);
    quicksort(a, i, r);
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
    int a[] = {2, 3, 5, 7, 6, 7, 8, 4, 2, 1, 1, 5, 6};
    int size = sizeof(a) / sizeof(int);
    printarr(a, size);
    quicksort(a, 0, size - 1);
    printarr(a, size);
    return 0;
} 