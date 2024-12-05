#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    vector<vector<int>> a;
    cin >> n;
    a.resize(2, vector<int> (n));

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
        }
    }
    ll sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        ll temp = a[0][i] + a[1][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                temp += max(a[0][j], a[1][j]);
            }
        } 
        sum = max (sum, temp);
    }
    cout << sum << "\n";
}

void solve(int in_linear_time) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int> (n));

     for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
        }
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max (a[0][i], a[1][i]);
    }

    ll ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max (ans, sum + min(a[0][i], a[1][i]));
    }
    cout << ans << "\n";
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
        solve(4);
    }

    return 0;
}