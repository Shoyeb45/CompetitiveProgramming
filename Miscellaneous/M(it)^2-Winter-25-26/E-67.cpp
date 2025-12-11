#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    ll num;
    cin >> num;
    return num;
}

void solve() {
    int n;
    cin >> n;

    vector<int> ans(n + 1);

    for (int i = 1; i <= n; ) {
        if (i + 2 <= n) {
            ll t1 = ask(i, i + 1);
            ll t2 = ask(i, i + 2);
            ll g = gcd(t1, t2);
            ans[i] = g;
            ans[i + 1] = t1 / g;
            ans[i + 2] = t2 / g;
            i += 3;
        } else {
            ll t1 = ask(i, i - 1);
            ans[i] = t1 / ans[i - 1];
            i++;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}   



int main() {
    NFS
 
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}