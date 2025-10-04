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


// type_a : 2^k
// type_b : 2^k + 1
// type_c : NOTA

// reducing each number is independent, just take care type_b

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pref(n + 1), type_b(n + 1), type_c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = (int) log2(a[i]);
        pref[i] = pref[i - 1] + x;
        
        bool is_type_a = !(a[i] & (a[i] - 1));
        bool is_type_b = ((1 << x) + 1 == a[i]);
        type_b[i] = type_b[i - 1] + int(is_type_b);
        type_c[i] = type_c[i - 1];
        if (!is_type_b && !is_type_a) {
            type_c[i]++;
        }
    }

 
    while (q--) {
        int l, r;
        cin >> l >> r;
        int a = pref[r] - pref[l - 1];
        int b = type_b[r] - type_b[l - 1];
        int c = type_c[r] - type_c[l - 1];
        cout << a + b / 2 + c << "\n";
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