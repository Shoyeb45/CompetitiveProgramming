#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));

    for (auto &x: a) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    for (auto &vec: a) {
        sort(range(vec));
    }
    // for (auto &x: a) {
    //     for (auto &y: x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        p.push_back(make_pair(a[i][0], i));
    }
    sort(range(p));

    int top = p.back().first;

    vector<int> idxs(n, 1);
    int iter = 1;

    while (iter < m) {
        for (auto x: p) {
            // cout << "t " << top << "\n";
            if (a[x.second][idxs[x.second]] > top) {
                top = a[x.second][idxs[x.second]];
                idxs[x.second]++;
            }
            else {
                cout << -1 << "\n";
                return;
            }
        }
        iter++;
    }

    for (auto x: p) {
        cout << x.second + 1 << " ";
    }
    cout << "\n";
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