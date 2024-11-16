#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, d, l;
void solve() {
    
    cin >> n >> d >> l;

    if (n == 2 && d == 1 && l == 2) {
        cout << 1 << " " << 2 << "\n";
        return;
    }
    if (d == 1 || n - (d + 1) != l - 2) {
        cout << -1 << "\n";
        return;
    }

    vector<int> p(n + 1, 0);

    p[2] = 1;
    int parent = 1, child = 3;
    for (int i = 0; i < d - 1; i++) {
        p[child] = parent;
        if (i == 0) {
            parent += 2;
        }
        else {
            parent++;
        }
        child++;
    }
    for (int i = 0; i < l - 2; i++) {
        p[child++] = 1;
    }

    cout << 1 << " " << 2 << "\n";
    for (int i = 3; i <= n; i++) {
        cout << i << " " << p[i] << "\n";
    }
}

int main() {
    NFS
  
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}