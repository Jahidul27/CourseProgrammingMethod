//
// Created by islam on 9/19/2018.
//

#ifndef PM2HW1P4_2_PROBLEMSOLVINGB_H
#define PM2HW1P4_2_PROBLEMSOLVINGB_H
#include <iostream>
#include <map>

void ProblemFourB(int array[], int length, int sum)
{
    std::map<int, int> element;
    for (int i=0; i< length; ++i)
    {
        element.insert( std::pair<int, int>(array[i], 1));
        if(element.count(sum - array[i]) )
            printf("\n{%d, %d}", array[i], sum - array[i]);

    }
}
#endif //PM2HW1P4_2_PROBLEMSOLVINGB_H
