#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

vector<vector<int>> divisors;

void precompute_divisors(int n) {
    divisors.assign(n + 1, {});
    for (int d = 1; d <= n; d++) {
        for (int multiple = d; multiple <= n; multiple += d) {
            divisors[multiple].push_back(d);
        }
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;   

    ll ans = 0;
    int i = 0;
    vector<int> cnt(n + 1);
    if (s[i] == '0') {
        for (; i < n; i++) {
            if (s[i] == '1') {
                break;
            }
            auto di = divisors[i + 1];
            for (auto d: di) {
                cnt[d]++;
            }
            ans++;
        }
    }
    
    

    for (; i < n; i++) {
        if (s[i] == '0') {
            auto di = divisors[i + 1];
            int temp = i + 1;
            for (int d: di) {
                if (cnt[d] == ((i + 1) / d) - 1) {
                    temp = d;
                    break;
                }
            }
            for (int d: di) {
                cnt[d]++;
            }
            ans += temp;
        }
    }
   
    cout << ans << "\n";
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
    precompute_divisors(1e6);

    while (tt--) {
        solve();
    }

    return 0;
}