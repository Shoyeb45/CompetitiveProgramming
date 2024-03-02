// Sorted array - return the number of subarrays such that the sum of element is greater than k

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)  cin >> a[i];
    int k;
    cin >> k;
    int j = 0, currentSum = 0, ans = 0;
    for(int i=0; i<n; i++) {
        for(; j<n; j++) {
            if(currentSum + a[j] > k) {
                ans += (n-j);
                currentSum -= a[i];
                break;            
            } else {
                currentSum += a[j];
            }
        }
    }
    cout << ans ;
}