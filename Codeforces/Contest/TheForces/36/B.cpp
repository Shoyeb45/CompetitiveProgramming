#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int x, y, z;

bool check(vector<int> &t, int y, int occur[]) {
    for(auto x: t) {
        if(occur[x] >= y) {
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> x >> y >> z;

    if(x < z) {
        cout << 0 << "\n";
        return;
    }

    vector<vector<int>> ans;

    int occur[11] = {0};
    for(int i = 1; i < (1 << x); i++) {

        vector<int> t;
        for(int j = 0; j < ((int)log2(i) + 1); j++) {
            if(((i >> j) & 1)) {
                t.push_back(j + 1);
            }
        }

        if(t.size() == z) {
            if(check(t, y, occur)) {
                ans.push_back(t);
                for(auto x: t) {
                    occur[x]++;
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for(auto x: ans) {
        for(auto y: x) {
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