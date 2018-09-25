//
// Created by islam on 9/19/2018.
//

#ifndef PM2HW1P4_PROBLEMSOLVINGA_H
#define PM2HW1P4_PROBLEMSOLVINGA_H
#include <bits/stdc++.h>
using namespace std;


void ProblemFourA(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
#endif //PM2HW1P4_PROBLEMSOLVINGA_H
