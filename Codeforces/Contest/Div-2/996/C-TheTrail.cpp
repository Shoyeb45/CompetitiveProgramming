#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
void solve() {

    int n, m;
    vector<vector<ll>> a;
    string s;
    cin >> n >> m >> s;
    a.resize(n, vector<ll>(m));

    for (auto &x : a) {
        for (auto &y: x) {
            cin >> y;
        }
    }


    vector<ll> sumCol(m), sumRow(n);
    for (int i = 0; i < n; i++) {
        ll temp = 0;
        for (int j = 0; j < m; j++) {
            temp += a[i][j];
        }
        sumRow[i] = temp;
    }
    for (int j = 0; j < m; j++) {
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            temp += a[i][j];
        }
        sumCol[j] = temp;
    }
    int i = 0, j = 0;
    
    for (auto ch: s) {
        if (ch == 'D') {
            a[i][j] = -sumRow[i];
            sumCol[j] += a[i][j];
            i++;
        }
        else {
            a[i][j] = -sumCol[j];
            sumRow[i] += a[i][j]; 
            j++;
        }
    }

    if (s.back() == 'D') {
        a[i][j] = -sumRow[i];
        sumCol[j] += a[i][j];
        i++;
    }
    else {
        a[i][j] = -sumCol[j];
        sumRow[i] += a[i][j]; 
        j++;

    }
    for (auto x: a) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << "\n";
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