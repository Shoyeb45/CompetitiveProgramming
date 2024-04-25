#include<bits/stdc++.h>
using namespace std;

#define RUN 5

// Define the range of the test data generated
#define MAX 50000

// Define the maximum number of array elements
#define MAXNUM 50000

int main()
{
    srand(time(NULL));
    for (int i=1; i<=RUN; i++)
    {
        int NUM = 10;
        printf("%d\n", NUM);
        for (int j=1; j<=NUM; j++)
            printf("%d ", (rand() % (2*MAX))-(MAX));

        printf("\n");
    }
    return(0);
}