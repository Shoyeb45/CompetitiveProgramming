#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int x, y, a, b;
void solve() {
    cin >> x >> y >> a >> b;
    vector<pair<int, int>> ans;
    for(int i = a; i <= x; i++) {
        for(int j = b; j <= y; j++) {
            if(i > j) {
                ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto it: ans) {
        cout << it.first << " " << it.second << '\n';
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
