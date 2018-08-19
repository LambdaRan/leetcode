
//https://www.geeksforgeeks.org/find-all-distinct-subset-or-subsequence-sums-of-an-array-set-2/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
/*
* Name: 
* Description: 
*
*/
#include <bits/stdc++.h>
using namespace std;
 
// Function to print all th distinct sum
void subsetSum(int arr[], int n, int maxSum)
{
 
    // Declare a boolean array of size
    // equal to total sum of the array
    bool dp[maxSum + 1];
    memset(dp, false, sizeof dp);
 
    // Fill the first row beforehand
    dp[arr[0]] = true;
 
    // dp[j] will be true only if sum j
    // can be formed by any possible
    // addition of numbers in given array
    // upto index i, otherwise false
    for (int i = 1; i < n; i++) {
 
        // Iterate from maxSum to 1
        // and avoid lookup on any other row
        for (int j = maxSum + 1; j >= 1; j--) {
 
            // Do not change the dp array
            // for j less than arr[i]
            if (arr[i] <= j) {
                if (arr[i] == j || dp[j] || dp[(j - arr[i])])
                    dp[j] = true;
 
                else
                    dp[j] = false;
            }
        }
    }
    // If dp [j] is true then print
    cout << 0 << " ";
    for (int j = 0; j <= maxSum + 1; j++) {
        if (dp[j] == true)
            cout << j << " ";
    }
}
 
// Function to find the total sum
// and print the distinct sum
void printDistinct(int a[], int n)
{
    int maxSum = 0;
 
    // find the sum of array elements
 
    for (int i = 0; i < n; i++) {
        maxSum += a[i];
    }
 
    // Function to print all the distinct sum
    subsetSum(a, n, maxSum);
}
 
// Driver Code
int main()
{
    int arr[] = { 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printDistinct(arr, n);
    return 0;
}
