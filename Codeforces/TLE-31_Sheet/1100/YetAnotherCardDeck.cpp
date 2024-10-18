#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, q;
void solve() {
    cin >> n >> q;
    vector<int> a(51, INT_MAX);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = min(a[x], i);
    }

    while(q--) {
        int x;
        cin >> x;
        int ans = a[x];
        cout << ans << "\n";
        for(int &x: a) {
            if(x < ans) {
                x++;
            }
        }
        a[x] = 1;
    }

}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}