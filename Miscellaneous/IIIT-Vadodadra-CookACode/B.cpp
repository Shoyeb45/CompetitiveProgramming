#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int x, y;
void solve() {
    cin >> x >> y;

    queue<pair<ll, int>> q;

    unordered_map<ll, int> mp;
    q.push({x, 0});

    while (!q.empty()) {
        ll ele = q.front().first;
        int ope = q.front().second;

        if (ele == y) {
            cout << ope << "\n";
            return;
        }

        if (ele % 2 == 0 && mp.find(ele / 2) == mp.end() && ele / 2 >= y) {
            q.push({ele / 2, ope + 1});
            mp[ele / 2]++;
        }
        if (ele % 3 == 0 && mp.find(ele / 3) == mp.end() && ele / 3 >= y) {
            q.push({ele / 3, ope + 1});
            mp[ele / 3]++;
        }
        
        if (mp.find(ele - 1) == mp.end() && ele - 1 >= y) {
            q.push({ele - 1, ope + 1});
            mp[ele - 1]++;
        }
        q.pop();
    }
    cout << -1 << "\n";
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