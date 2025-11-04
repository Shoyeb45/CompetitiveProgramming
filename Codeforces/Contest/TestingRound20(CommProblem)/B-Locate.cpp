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

int ask(int l, int r) {
    int x;
    cout << "? " << l << " " << r << endl;
    cin >> x;
    return x;
}

void solve_first() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }
    for (int x: a) {
        if (x == 1) {
            cout << 1 << endl;
            return;
        } else if (x == n) {
            cout << 0 << endl;
            return;
        }
    }
}

void solve_second() {
    int n, x;
    cin >> n >> x;
    int l = 1, r = n;
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int diff = ask(1, mid);
        if (diff == n - 1) {
            l = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int diff = ask(mid, n);

        if (diff == n - 1) {
            r = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (l > r) {
        swap(l, r);
    }

    // 1 lies before n, 
    // l -> 1, r -> n
    if (x == 1) {
        swap(l, r);
    }
    cout << "! " << l << endl;
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    string s;
    cin >> s;
    int tt;
    tt = 1;
    cin >> tt;

    void (*solve)();
    if (s == "first") {
        solve = solve_first;
    } else {
        solve = solve_second;
    }

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}