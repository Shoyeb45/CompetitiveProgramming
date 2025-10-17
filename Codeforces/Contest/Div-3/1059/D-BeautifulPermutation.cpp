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

map<string, int> mp;

int ask(int type, int l, int r) {
    string query = to_string(type) + " " + to_string(l) + " " + to_string(r);
    // if (mp.find(query) != mp.end()) {
    //     return mp[query];
    // }
    cout << query << endl;
    int x;
    cin >> x;
    return mp[query] = x;
}

void solve() {
    int n;
    cin >> n;

    int p_sum = ask(1, 1, n);
    int a_sum = ask(2, 1, n);
    int k = a_sum - p_sum;

    int lo = 1, hi = n;
    int l = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int diff = ask(2, 1, mid) - ask(1, 1, mid);
        if (diff > 0) {
            l = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    // cout << "For r\n ";
    // lo = l, hi = n;
    // int r = -1;
    // while (lo <= hi) {
    //     int mid = (lo + hi) / 2;
    //     int diff = ask(2, 1, mid) - ask(1, 1, mid);
    //     if (diff == (mid - l + 1)) {
    //         r = mid;
    //         lo = mid + 1;
    //     } else {
    //         hi = mid - 1;
    //     }
    // }
    cout << "! " << l << " " << l + k - 1 << endl;
    mp.clear();
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE 
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}