//Problem 2 for mergesort
#include <bits/stdc++.h>
using namespace std;
void mergeSort(int a[],int front, int mid, int last,  int arraySize) //Initializing the components needed for the merge sorting
{
    //This portion sets up typical movement of integers for sorting

    int i = front;
    int j = mid + 1;
    int k = front;

    //moves higher values to the right after selecting pivot

    while (i <= mid && j <= last) {
        if (a[i] % arraySize <= a[j] % arraySize) {
            a[k] = a[k] + (a[i] % arraySize) * arraySize;
            k++;
            i++;
        }
        else {
            a[k] = a[k] + (a[j] % arraySize) * arraySize;
            k++;
            j++;
        }
    }
    while (i <= mid) {
        a[k] = a[k] + (a[i] % arraySize) * arraySize;
        k++;
        i++;
    }


    //moves lower values to the left

    while (j <= last) {
        a[k] = a[k] + (a[j] % arraySize) * arraySize;
        k++;
        j++;
    }



    for (int i = front; i <= last; i++)
        a[i] = a[i] / arraySize;
}




//Recursive merge sort with extra parameter, y begins below. For integer types, meaning only integers are used in an array, merge sort can be made inplace using some mathematics.
//That means storing the value of two elements at a single index and can be extracted using modulus and division. In order to do this properly,
//first we have to find a value greater than all the elements of the array. Now we can store the original value as modulus and the second value as division.
//Since this process is used it becomes a O(1) instead of an O(n) thereby meaning that the time can be concluded to be NlogN as this is what mergesort provides
//according to the chart.


//Here the mergesorts can be seen
void mergeSortRec(int a[], int front, int last, int y)
{
    if (front < last) {
        int mid = (front + last) / 2;
        mergeSortRec(a, front, mid, y);
        mergeSortRec(a, mid + 1, last, y);
        mergeSort(a, front, mid, last, y);
    }
}

// This functions finds the max element and calls recursive and then the merge sort process begins.
// Some bottlenecking may occur as it requires multiple mergesorts to complete the process, however it should still be time efficient.


void mergeSort(int a[], int n)
{
    int max = *max_element(a, a+n) + 1;// finds the largest
    mergeSortRec(a, 0, n-1, max);
}






//This is the part to be manipulated

int main()
{
    int arr[] = { 123, 456, 789, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    cout << "The array you inputsorted will be \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}







//This mergesort is stable as can be seen in the starting portions of the code. This is because when merging two halves,
//the left and right values are taken into accountance after being split meaning that when another mergesort is performed
//the previous sorting is remembered. It can be seen here were multiple mergesorts are used:
// if (beg < end) {
//        int mid = (beg + end) / 2;
//        mergeSortRec(arr, beg, mid, y);
//        mergeSortRec(arr, mid + 1, end, y);
//        mergeSort(arr, beg, mid, end, y);
//    }