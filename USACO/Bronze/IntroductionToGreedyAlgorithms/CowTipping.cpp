#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<string> a;
void solve() {
    cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    auto flip = [&](char c) -> char {
        return c == '1' ? '0': '1';
    };

    auto update = [&](int x, int y) -> void {
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                a[i][j] = flip(a[i][j]);
            } 
        }
    };

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if(a[i][j] == '1') {
                ans++;
                update(i, j);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
        freopen("cowtip.in", "r", stdin);
        freopen("cowtip.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}