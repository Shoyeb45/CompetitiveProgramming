// we have arrays of 1 and 0 (binary array), and we have k, number of operation to toggle the bit in array. Find the maximum length of subarray - which contains only ones

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)  cin >> a[i];
    int k;
    cin >> k;
    int operation = 0, ans = 0;

// 1. Brute Force approach

    // for(int i=0; i<n; i++) {
    //     operation = 0;
    //     for(int j=i; j<n; j++) {
    //         if(a[j] == 0)   operation++;
    //         if(operation <= k) {
    //             ans = max(ans, j-i+1);
    //         } else {
    //             break;
    //         }
    //     }
    // }    

// 2. optimized method
    int j=0;
    for(int i=0; i<n; i++) {
        int operation = 0;
        for(; j<n; j++) {
            if(a[j] == 0)   operation++;
            if(operation <= k) {
                ans = max(a[i], j-i+1);
            }
        }
    }
    cout << ans;

// 3. Binary Method


}