#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;
const int N = 1e3 + 1;
vector<int> primes;
void sieve() {
    int is_p[N];
    fill(is_p, is_p + N, true);

    is_p[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_p[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                is_p[j] = false;
            }
        }
    }
}

map<int, int> factorize(int x) {
    map<int, int> mp;
    for (int p: primes) {
        if (p > x) {
            break;
        }
        if (x % p == 0) {
            while (x % p == 0) {
                x /= p;
                mp[p]++;
            }
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    return mp;
}
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    if (k == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (k <= n) {
        cout << "YES\n";
        if (n == 1) {
            cout << 1 << "\n";
            return;
        }
        cout << 1 << " " << k << " ";
        for (int i = 2; i <= n; i++) {
            if (i != k) {
                cout << i << " ";
            }
                
        }
        cout << "\n";
        return;
    }
    map<int, int> mp = factorize(k);
    set<int> ans;
    for (auto it : mp) {
        ll p = (ll) pow(it.first, it.second);
        if (p > n) {
            cout << "NO\n";
            return;
        }
        ans.insert(p);
    }
    cout << "YES\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    for (int i = 1; i <= n; i++) {
        if (ans.find(i) == ans.end()) {
            cout << i << " ";
        }
    }
    cout << "\n";
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
    sieve();

    while (tt--) {
        solve();
    }

    return 0;
}