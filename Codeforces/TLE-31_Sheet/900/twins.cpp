#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++)  sum += a[i];

    return sum;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n; i++)   cin >> a[i];
    sort(a, a+n);
    int min = 0, max = 0;

    int Sum = sum(a, n);
    int tempSum = 0;
    int ans = 0;
    for(int i=n-1; i>=0; i--) {
        tempSum += a[i];
        if(tempSum > Sum - tempSum) {
            ans = n - i;
            break;
        }
    }

    cout << ans; 
    return 0;
}