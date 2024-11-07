#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> p;

void solve() {
    cin >> n;
    p.resize(n);
    for(auto &x : p) {
        cin >> x;
    }

    int ans = n;
    reverse(range(p));

    for(int i = 0; i < n - 1; i++) {
        if(p[i] < p[i + 1]) {
            ans = i + 1;
            break;
        }
    }
    cout << n - ans << "\n";
}

int main() {
    NFS
        freopen("sleepy.in", "r", stdin);
        freopen("sleepy.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}