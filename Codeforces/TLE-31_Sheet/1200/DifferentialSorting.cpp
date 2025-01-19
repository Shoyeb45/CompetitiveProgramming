#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> a(n);
    // a.resize(n);

    for (auto &x : a) {
        cin >> x;
    }

    if (is_sorted(range(a))) {
        cout << 0 << "\n";
        return;
    }

    if (a[n - 1] < a[n - 2] || a[n - 1] < 0) {
        cout << -1 << "\n";
        return;
    }
    
    vector<tuple<int, int, int>> ans;
    
    for (int i = n - 3; i >= 0; i--) {
        a[i] = a[n - 2] - a[n - 1];
        ans.push_back(make_tuple(i, n - 2, n - 1));
    }

    // for (auto x : a) {cout << x << " ";}
    // cout << "\n";
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << get<0>(x) + 1 << " " << get<1>(x) + 1 << " " << get<2>(x) + 1 << "\n";
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