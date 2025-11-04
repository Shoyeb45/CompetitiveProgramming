#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

bool is_overlapping(pair<int, int> &p1, pair<int, int> &p2) {
    return !(p1.first  > p2.second || p2.first > p1.second);
}

vector<pair<int, int>> merge_overlapping_intervals(vector<pair<int, int>> &a) {
    sort(range(a));
    vector<pair<int, int>> ans = {a[0]};
    for (int i = 1; i < a.size(); i++) {
        if (is_overlapping(ans.back(), a[i])) {
            pair<int, int> p = {min(ans.back().first, a[i].first), max(ans.back().second, a[i].second)};
            ans.pop_back();
            ans.push_back(p);
        } else {
            ans.push_back(a[i]);
        }
    } 
    return ans;
}

void solve() {
    int y, x, n;
    cin >> y >> x >> n;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        int _x, _y, r;
        cin >> _x >> _y >> r;
        int l = max(0, _x - r), r_ = min(x, _x + r);
        intervals.push_back({l, r_});
    }   


    vector<pair<int, int>> merged_interval = merge_overlapping_intervals(intervals);
    int ans = x;
    for (auto p: merged_interval) {
        ans -= p.second - p.first;
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

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}