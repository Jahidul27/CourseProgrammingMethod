#include <iostream>
#include "ProblemSolving3.h"
using namespace std;

int main()
{
    int arr[] = {1, 7, 9, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " <<  ProblemFourC(arr, n, k);
    return 0;
}