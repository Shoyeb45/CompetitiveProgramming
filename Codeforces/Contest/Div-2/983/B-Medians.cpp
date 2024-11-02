#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
void solve() {
    cin >> n >> k;

    if(k == (n + 1) / 2 || n == 1) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        return; 
    }

    if(k == n || k == 1) {
        cout << -1 << "\n";
        return;
    }

    if(k % 2 == 1) {
        cout << 5 << "\n";
        cout << "1 2 " << k << " " << k + 1 << " " << n << "\n";
    }   
    else {
        cout << 3 <<  "\n";
        cout << 1 << " " << k << " " << k + 1 << "\n";
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