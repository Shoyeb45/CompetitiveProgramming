#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, d;
    cin >> n >> d;
    ll x[n];
    for(int i=0; i<n; i++)  cin >> x[i];
    ll ans = 0;

    // Brute force - working code
    // for(int i=0; i <= n - 3; i++) {
    //     for(int j=n-1; j >= i+2; j--) {
    //         if(abs(x[i] - x[j]) <= d) {
    //             ans += (j-i-1);
    //         } 
    //     }
    // }

    for(int i=0; i <= n - 3; i++) {
        for(int j=i+2; j <= n; j++) {
            if(abs(x[i] - x[j]) <= d) {
                ans += (j-i-1);
            } else {
                break;
            }
        }
    }

    // for(ll i = 0, j = 0; i < n; i++){
    //     while (x[i] - x[j] > d) j++;

    //     ans += ((i - j) * (i - j - 1))/2;
    // }
    cout << ans;
}