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
const int MAX_N = 250000;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0), cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[i] = 0;
    }     
    cnt[0] = (a[0] == 1);
    vector<int> cons_one(n, 0), cons_zero(n, 0);

    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1] + (a[i] == 1);
        cons_one[i] = cons_one[i - 1] + (a[i] == a[i - 1] && a[i] == 1);
        cons_zero[i] = cons_zero[i - 1] + (a[i] == a[i - 1] && a[i] == 0);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len < 3) {
            cout << -1 << "\n";
            continue;
        }
        l--, r--;
        int cnt_one = cnt[r] - (l - 1 < 0 ? 0 :cnt[l - 1]); 
        int cnt_zero = (len) - cnt_one;

        if (cnt_one % 3 != 0 || cnt_zero % 3 != 0) {
            cout << -1 << "\n";
            continue;
        }
        
        int k1 = cnt_one / 3, k0 = cnt_zero / 3;
      
        int ans;
        int cn_1 = cons_one[r] - cons_one[l];
        int cn_0 = cons_zero[r] - cons_zero[l];

        if (cn_1 > 0 || cn_0 > 0) {
            ans = k1 + k0;
        } else {
            ans = k1 + k0 + 1;
        }
        cout << ans << "\n";
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