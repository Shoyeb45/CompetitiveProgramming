#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, l;
vector<pair<int, int>> hurdles;
vector<pair<int, ll>> powerups;

bool check() {
    ll power = 1;
    map<int, ll> mp;
    for (auto it: mp) {
        mp[it.first] += it.second;
    }

    int i = 0;
    for (auto it: mp) {
        if (it.first < hurdles[i].first - 1) {
            power += it.second;
        }
        else if (it.first == hurdles[i].first - 1) {
            power += it.second;
            if (it.first + power < hurdles[i].second + 1) {
                return false;
            }
            i++;
        }
        else {
            if (hurdles[i].first - 1 + power < hurdles[i].second + 1) {
                return false;
            }
            power += it.second;
            i++;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m >> l;
    hurdles.resize(n);
    
    for (auto &it : hurdles) {
        cin >> it.first >> it.second;
    }

    for (int i = 0, x, v; i < m; i++) {
        cin >> x >> v;
        powerups.push_back({x, v});
    }

    if(!check()) {
        cout << -1 << "\n";
        return;
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}