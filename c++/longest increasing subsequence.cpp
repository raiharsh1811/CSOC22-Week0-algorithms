
/* Dynamic Programming C/C++ implementation of LIS problem */
#include <iostream>
using namespace std;
 
/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int *lis, i, j, max = 0;
    lis = (int*)malloc(sizeof(int) * n);
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++)
        lis[i] = 1;
 
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
 
    return max;
}