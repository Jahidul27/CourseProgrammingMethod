#include <iostream>

using namespace std;

//This Bubblesort function is uesd to sort the array in ascending order which is one way to sort by maxima
//It is one method possible to sort this kind of an array

void Problem4(int a[],int n){

    for(int i=n-1;i>=0;i--){

        for(int j=0;j<i;j++){

            if(a[j]>a[j+1]){

                int temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;

            }

        }

    }

}
//Here begins the process of swapping integers based on their size
void swap(int *x, int *y)

{

    int temp = *x;

    *x = *y;

    *y = temp;

}
//The main fuction will prompt the user for the inputs before sorting can begin
int main(){

    int n;

    cout<<"Enter size of array : ";

    cin>>n;

    int arr[n];

    cout<<"Enter array \n";

    for(int i=0;i<n;i++){

        cin>>arr[i];

    }

    Problem4(arr,n);

    for (int i=0; i<n-1; i += 2)

        swap(&arr[i], &arr[i+1]);

    for(int i=0;i<n;i++){

        cout<<arr[i];

        if(i!=n-1)cout<<" ,";

    }

    return 0;

}


//Bubblesort can be considered similar to a type of mergesort because it sorts by dividing into groups and swapping which can be seen here:
//void swap(int *x, int *y)
//
//{
//
//    int temp = *x;
//
//    *x = *y;
//
//    *y = temp;

//Due to this, we can say the complexity can be summed up as NlogN similar to the mergesort's complexity. Overall,the efficiency in such
//a sort is good. In order for a linear time solution to be possible you must first find the largest or smallest number in the array and use that
//as a basis to sort local maxima or local minima around that chosen integer. Thus a mergesort can be used to accomplish this with O(N) complexity.