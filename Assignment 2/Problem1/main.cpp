#include<stdio.h>
#include<string.h>
//Problem 1 Sort
int main()
{
    int x[3]={12,9001,5}; // You can input any random array with an array size here in order for the process to begin
    int y[5][3]; // 5 represents the number of digits taken into consideration while 3 is the size of the array
    int low=x[0]; //least or start of array
    int c=0;
    int pos;
    int k=1;
    int i,j;
    int m=0;
    int a=0;
    int n;
// To begin with we have our array values and sizes pre-determined and initialized. The first part will find find the largest number from the given array.
// This is so that we can next determine how many times the sorting by digits place needs to be done in order to get all the places.
// Finding the maximum has an order of growth of linear N as stated in the lecture chart.
    for(i=0;i<3;i++)
    {
        if(low<x[i])
            low=x[i];
    }
// The number of time the comparison will occur depends on the largest number and how many digits it aforementioned largest number has.
// This set loop will continue until the largest number becomes zero. Since it is a loop it is thus N in order of growth.
    while(low>0)
    {
        c++;
        low=low/5;
    }
    for(i=0;i<c;i++)
    {
        memset(y,0,sizeof(y)); //All the values of the double dimension array is being set to zero by utilizing memset function

// This next part is put inside the double dimensional array
        for(j=0;j<3;j++)
        {
            pos=(x[j]/k)%5; //This will start the procedure of finding the position number at which index number of double dimensional array it will be put.

            while(y[pos][m]!=0) // Now we need to check at which position of double dimensional array the value is zero and also where we will put our element.
                m++;

            y[pos][m]=x[j]; //After the search m is the position found , now this element can be put inside the double dimensional array
            m=0; // reset m for next element
        }
// This next part will retrieve the data from the double dimensional array
        for(j=0;j<5;j++) // We can see traversing occur in the double dimensional array
        {
// Now we will proceed to retrieve all elements from the double dimensional array at the particular index number
            while(y[j][m]!=0)
            {
                x[a]=y[j][m]; // This does the storing elements back to our given array after each sorting or comparison from the double dimensional array
                a++; // Now we continue incrementing index value of the given array
                m++;
            }
            m=0;
        }
//With this portion we can see that the elements we sorted are stored back to our given array and than the value of the index is increased.
//This will allow for the next digit place to be sorted. We can see that it has to go through this entire process each time and then repeat for another
//digit place meaning it could have a long run time. In total there are about 6 loops with the linear order of growth of N. This increases the runtime
//a decent amount.

        a=0; // This has the job of resetting index value of the given array to begin the process anew
        k=k*5;

        printf("\nThe number of digits we compared is %d. Thus the new array is: \n",i+1);

        for(n=0;n<3;n++){
            printf("%d ",x[n]);
        }
    }

    printf("\n");

    return 0;
}

//The code is not stable as we can see from this portion:
// while(y[j][m]!=0)
//            {
//                x[a]=y[j][m]; // This does the storing elements back to our given array after each sorting or comparison from the double dimensional array
//                a++; // Now we continue incrementing index value of the given array
//                m++;
//            }
//            m=0;
//D)Since the index is moving each time the previous sort is not taken into account meaning the sorting each time has no sorting relations to the previous sort.
//E)Constant extra space implies that regardless of n the code will always have the same runtime. Since my code checks each value in the array
//it does not currently use O(1) because adding more values would increase the runtime.


//In order to implement it we must do for example:

//int i = 0;
//    while (i<n)
//    {
//        // If this element is already processed,
//        // then nothing to do
//        if (arr[i] <= 0)
//        {
//            i++;
//            continue;

//Initializing i as zero and then finding elements of the array corresponding to a given index would mean all elements corresponding to that index would
//be sorted accordingly rather than comparisons in between them being made. Thus the runtime would be the same no matter the size of the array.