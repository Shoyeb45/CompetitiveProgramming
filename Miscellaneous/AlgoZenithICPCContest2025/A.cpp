#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;



void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int> (3, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    auto cmp = [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0]; 
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    int dx[] = {1, 0};
    int dy[] = {0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < n && ny < 3) {
                    vector<int> temp = {a[i][j] + a[nx][ny], i, j, nx, ny};
                    pq.push(temp);
                }
            }
        }
    }
    vector<set<int>> idxs(n + 1);
    auto check = [&](vector<int> &d) -> bool {
        int x1 = d[1], y1 = d[2];
        int x2 = d[3], y2 = d[4];
        if (idxs[x1].find(y1) == idxs[x1].end() && idxs[x2].find(y2) == idxs[x2].end()) {
            return true;
        }
        return false;
    };

    int ans = 0;
    while (!pq.empty() && k) {
        vector<int> temp = pq.top();
        if (check(temp)) {
            ans += temp[0];
            int x1 = temp[1], y1 = temp[2];
            int x2 = temp[3], y2 = temp[4];
            idxs[x1].insert(y1), idxs[x2].insert(y2);
            k--;
            // cout << k << '\n';
        }
        pq.pop();
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}