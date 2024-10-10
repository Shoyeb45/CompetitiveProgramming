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
    vector<vector<int>> a(n, vector<int> (n)), b(n, vector<int> (n));
    for(auto &vec: a) {
        for(auto &x: vec) {
            cin >> x;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            b[i][j] = a[n - i - 1][n - j - 1];
        }
    }

    int x = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != b[i][j]) {
                x++;
            }
        }
    }

    x /= 2;
    
    if(x <= k) {
        if((n & 1) == 1) {
            cout << "YES\n";
        }
        else if((k - x) % 2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        cout << "NO\n";
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
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}