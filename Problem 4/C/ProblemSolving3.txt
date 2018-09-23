//
// Created by islam on 9/19/2018.
//

#ifndef PM2HW1P4_3_PROBLEMSOLVING3_H
#define PM2HW1P4_3_PROBLEMSOLVING3_H
#include<iostream>
#include<algorithm>
using namespace std;


int ProblemFourC(int arr[], int n, int k)
{
   
    sort(arr, arr+n);

    return arr[k-1];
}
#endif //PM2HW1P4_3_PROBLEMSOLVING3_H
