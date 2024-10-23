#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<ll> a;

bool check(ll x) {
    for(int i = 0; i < n - 1; i++) {
        if((a[i] % x != 0 && a[i + 1] % x != 0) || (a[i] % x == 0 && a[i + 1] % x == 0)) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll gcd1 = 0, gcd2 = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            gcd1 = __gcd(a[i], gcd1);
        }
        else {
            gcd2 = __gcd(a[i], gcd2);
        }
    }

    if(check(gcd1)) {
        cout << gcd1 << "\n";
    }
    else if(check(gcd2)) {
        cout << gcd2 << "\n";
    }
    else {
        cout << 0 << "\n";
    }

}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}