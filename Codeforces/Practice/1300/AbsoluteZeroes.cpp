#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<ll> a;

void solve() {
    cin >> n;
    a.resize(n);

    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 != a[i + 1] % 2) {
            cout << -1 << "\n";
            return;
        }
    }    


    if (a.front() % 2 == 0) {
        cout << 31 << '\n';
    }
    else {
        cout << 30 << "\n";
    }

    for (int i = 29; i >= 0; i--) {
        int k = (1 << i);
        cout << k << " ";
    }

    if (a.front() % 2 == 0) {
        cout << 1 << "\n";
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