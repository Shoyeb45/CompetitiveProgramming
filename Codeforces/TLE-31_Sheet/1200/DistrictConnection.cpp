#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
bool isAllEqual(vector<int> &a) {
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (isAllEqual(a)) {
        cout << "NO\n";
        return;
    }

    vector<int> parent(n + 1, -1);

    int idx = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[1]) {
            parent[i] = 1;
            idx = i;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[1]) {
            parent[i] = idx;
        }
    }

    cout << "YES\n";
    for(int i = 2; i <= n; i++) {
        cout << i << ' ' << parent[i] << "\n";
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