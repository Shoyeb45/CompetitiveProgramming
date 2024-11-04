#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<int> r, a;

void f(int idx) {
    if(idx == n) {
        int sum = 0;

        for(auto x : a) {
            sum += x;
        }

        if(sum % k == 0) {
            for(int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == a.size() - 1];
            }
        }
        return;
    }

    for(int i = 1; i <= r[idx] ; i++) {
        a[idx] = i;
        f(idx + 1);
    }
}
void solve() {
    cin >> n >> k;
    r.resize(n), a.resize(n);
    for(auto &x : r) {
        cin >> x;
    }
    f(0);
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