#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

pair<int,int> remainder(vector<int> &a, int k) {
    ll ans = 1;
    int rem = INT_MAX;
    loop(i, a.size()) {
        ans %= k;
        ans *= (a[i] % k);
        rem = min(rem, k - (a[i] % k));
    }
    return {ans % k, rem};
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        int even = 0;
        loop(i, n) { 
            cin >> a[i];
            even += (a[i] % 2 == 0);
        }

        pair<int, int> r = remainder(a, k);
        if(k == 2 || k == 3 || k == 5) {
            if(!(r.first))  cout << 0 << endl;
            else    cout << r.second << endl;
        } else {
            if(!(r.first))  cout << 0 << endl;
            else if(n >= 2)  cout << min(r.second, max(0, 2 - even)) << "\n";
            else {
                int ans = !(a[0] % k) ? 0 : 4 - (a[0] % k);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
