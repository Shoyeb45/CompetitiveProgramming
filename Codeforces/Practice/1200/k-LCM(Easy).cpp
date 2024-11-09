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

    if (n % 3 == 0) {
        for (int i = 0; i < 3; i++) {
            cout << n / 3 << " \n"[i == 2];
        }
    }    
    else if (n % 2 == 0) {
        if (((n - 2) / 2) % 2 == 0) {
            cout << 2 << " ";
            int k = (n - 2) / 2;
            cout << k << " " << k << "\n";
        }
        else {
            cout << n / 2 << " ";
            n /= 4;
            cout << n << " " << n << "\n";
        }
    }
    else {
        cout << 1 << " ";
        int k = (n - 1) / 2;
        cout << k << " " << k << "\n";
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