#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int lcm(ll a, ll b) {
    return ((a * b) / (__gcd(a, b)));
}
int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    
    ll deno = 1;
    vector<ll> ans(n, 0);
    loop(i, n) {
        cin >> a[i];
        deno = lcm(deno, a[i]);
    }

    ll sum = 0;
    loop(i, n) {
        ans[i] = deno / a[i];
        sum += ans[i];
    }

    if(sum < deno) {
        loop(i, n) {
            cout << ans[i] << ' ';
        }

    } else {
        cout << -1;
    }
    cout << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
