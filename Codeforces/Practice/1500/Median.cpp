#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }   
    int ans = 0;
    sort(range(a));
    if (!binary_search(range(a), x)) {
        a.push_back(x);
        sort(range(a));
        ans++;
    }
    // value exists, find the current position
    n = a.size();
    debug(a);
    int l, r;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            r = i;
            if (r + 1 == (n + 1) / 2) {
                cout << ans << "\n";
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            l = i;
            break;
        }
    }
    
    if (r + 1 > (n + 1) / 2) {
        ans = ans + (2 * l + 1) - n;
        cout << ans << "\n";
        return;
    }
    debug(l, r);
    ans = ans + n - (2 * r + 2);
    cout << ans  << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}