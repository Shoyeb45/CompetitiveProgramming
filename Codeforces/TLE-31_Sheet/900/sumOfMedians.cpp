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
        int m = n * k;
        vector<int> a(m);

        loop(i, m) cin >> a[i];

        int pos = n/2, ind = a.size() - pos - 1;
        ll ans = 0;
        for(int i = 1; i <= k; i++) {
            ans += a[ind];
            ind -= (pos + 1);
        }
        cout << ans << endl;
    }
}
