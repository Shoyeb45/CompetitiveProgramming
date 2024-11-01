#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> b, t;
void solve() {
    cin >> n;
    t.resize(n), b.resize(n - 1);
    for(auto &x: t) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }
    sort(range(b)), sort(range(t));

    for(int i = 0; i < n - 1; i++) {
        if(b[i] < t[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        if(t[i + 1] > b[i]) {
            cout << t[i + 1] << "\n";
            return;
        }
    }
    cout << t.front() << "\n";
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