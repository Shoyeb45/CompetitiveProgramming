#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        ll sum = 0;
        loop(i, n) { 
            cin >> a[i];
            sum += a[i];
        }

        ll b = sum;
        while(q--) {
            sum = b;
            ll l, r, k;
            cin >> l >> r >> k;
            for(int i = l - 1; i < r; i++) {
                sum += (k - a[i]);
            }
            if((sum % 2) == 1)  cout << "YES\n";
            else    cout << "NO\n";
       }
    }

        return 0;
}