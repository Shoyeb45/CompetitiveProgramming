#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;



int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        loop(i, n)  cin >> a[i];

        sort(a.begin(), a.end());

        int current = 1, total = 0;
        loop(i, n - 1) {
            if(abs(a[i] - a[i + 1]) <= k)   current++;
            else {
                total = max(total, current);
                current = 1;
            }
        }

        total = max(total, current);
        cout << n - total << "\n";
    }

    return 0;
}
