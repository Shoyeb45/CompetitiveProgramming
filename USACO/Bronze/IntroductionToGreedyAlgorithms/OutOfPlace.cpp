#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a, b;
void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    b = a;
    sort(range(a));

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            k++;
        }
    }
    k = max(k - 1, 0);
    cout << k << "\n";
}

int main() {
    NFS
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}