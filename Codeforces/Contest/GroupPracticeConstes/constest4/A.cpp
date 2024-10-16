#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;

bool isPerfectSq(int x) {
    int sq = (int) sqrt(x);
    return sq * sq == x;
}
void solve() {
    cin >> n >> m;

    set<pair<int, int>> vp;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            vp.insert(make_pair(i, j));
        }
    }

    vector<pair<int, int>> a;
    for(auto it = vp.begin(); it != vp.end(); it++) {
        a.push_back(*it);
    }

     for(auto it: a) {
        cout << it.first << " " << it.second << '\n';
    }

    vector<pair<int, vector<pair<int, int>>> > ans;

    for(int i = 0; i < a.size() - 1; i++) {
        bool flag = 1;
        vector<pair<int, int>> temp = {a[i]};
        for(int j = i + 1; j < a.size(); j++) {
            int x1 = a[i].first, y1 = a[i].second;
            int x2 = a[j].first, y2 = a[j].second;
            int sqd = abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1);

            if(!isPerfectSq(sqd)) {
                temp.push_back(a[j]);
            }
        }
        ans.push_back(make_pair(temp.size(), temp));
    }
    
    sort(ans.rbegin(), ans.rend());

    cout << ans[0].second.size() << "\n";
    for(auto it: ans[0].second) {
        cout << it.first << " " << it.second << '\n';
    }

}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}