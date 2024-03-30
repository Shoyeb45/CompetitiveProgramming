#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSorted(vector<ll> &a) {
    bool ans = true;
    for(int i = 0 ; i < a.size() - 1; i++) {
        if(a[i] <= a[i+1])   ans = ans && true;
        else    ans = false;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        
        if(!isSorted(a)) cout << 0 << '\n';
        else {
            ll minDiff = INT_MAX;
            for(int i = 1; i < n; i++) {
                if(minDiff >= (a[i] - a[i-1]))  minDiff = a[i] - a[i-1];
            }

            cout << (minDiff/2) + 1 << '\n';
        }
    }
}