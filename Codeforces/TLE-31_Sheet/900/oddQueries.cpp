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

        vector<ll> a(n);
        vector<ll>  pS;

        loop(i, n) { 
            cin >> a[i];
        }

        pS.push_back(a[0]);
        for(int i = 1; i < n ; i++) {
            pS.push_back(pS[i - 1] + a[i]);
        }

        while(q--) {
            ll l, r, k;
            cin >> l >> r >> k;
            ll sumBtw = 0;
            
            if(l == 1)  sumBtw = pS[r - 1];
            else    sumBtw = pS[r - 1] - pS[l - 2];

            ll sum = (pS[n - 1] - sumBtw) + (r - l + 1) * k;
            
            if((sum % 2) == 1)  cout << "YES\n";
            else    cout << "NO\n";
       }
    }

        return 0;
}