// finding pair of indices in a sorted array such that sum of values at those indices should be equal to k.
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)  cin >> a[i];
    int k;
    cin >> k;
    int i = 0, j = n-1;
    while(i<j) {
        if(a[i] + a[j] == k) {
            cout << i << " " << j <<'\n';
            break;
        } else if (a[i] + a[j] > k) {
            j--;
        } else {
            i++;
        }
    }
}

// solution : 
// 1. Brute force approach - O(n^2)
// 2. Binary Search approach - O(nlogn)
// 3. unique approach - we'll check sum from starting and ending, because if the sum of element at i=0 and j=n-1 is greater than k , then the sum will exist left side from the jth element.  - O(n)