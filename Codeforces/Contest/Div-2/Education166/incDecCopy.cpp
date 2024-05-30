#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int extra_ope(vector<ll> &a, vector<ll> &b) {
    int n = a.size();

    loop(i, n) {
        // if((a[i] == b[n]) || (a[i] > b[n] && b[i] < a[i] && b[i] <= b[n]) || (a[i] < b[n] && b[i] > a[i] && b[i] >= b[n]))
        if((a[i] == b[n]) || (a[i] > b[n] && b[i] <= b[n]) || (a[i] < b[n]  && b[i] >= b[n]))
            return 1;
    }
    int a_op = INT_MAX, b_op = INT_MAX;

    loop(i, n) {
        a_op = min(a_op, (int)(abs(b[n] - a[i])));
        b_op = min(b_op, (int)(abs(b[n] - b[i])));
    }
    return min(a_op, b_op) + 1;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n + 1);
    loop(i, n) {
        cin >> a[i];
    }
    loop(i, n + 1) {
        cin >> b[i];
    }

    ll ans = 0;
    loop(i, n) {
        ans += abs(a[i] - b[i]);
    }

    ans += extra_ope(a, b);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
