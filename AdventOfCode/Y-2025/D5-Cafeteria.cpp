#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

bool is_overlapping(pair<ll, ll> &p1, pair<ll, ll> &p2) {
    return !((p1.second < p2.first) || p2.second < p1.first);
}

vector<pair<ll, ll> > merge_overlapping_intevals(vector<pair<ll, ll> > &a) {
    sort(range(a));
    vector<pair<ll, ll> > ans;
    ans.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        auto p = ans.back();
        if (is_overlapping(p, a[i])) {
            ans[ans.size() - 1] = make_pair(min(p.first, a[i].first), max(p.second, a[i].second));
        } else {
            ans.push_back(a[i]);
        }
    }
    return ans;
}

void solve() {
    vector<pair<ll, ll> > intervals;
    vector<ll> ids;

    string s;
    while (cin >> s) {
        int idx = s.find('-');
        if (idx != -1) {
            ll l = stoll(s.substr(0, idx));
            ll r = stoll(s.substr(idx + 1));
            intervals.push_back(make_pair(l, r));
        } else {
            ids.push_back(stoll(s));
        }
    }
     
    // part 1 
    // int ans = 0;
    // sort(range(intervals));
    // for (int i = 0; i < ids.size(); i++) {
    //     ll x = ids[i];
    //     for (int j = 0; j < intervals.size(); j++) {
    //         if (intervals[j].first > x) 
    //             break;
    //         if (x <= intervals[j].second) {
    //             ans++;
    //             break;
    //         }
    //     }
    // }
    // cout << ans << "\n";

    // part 2
    intervals = merge_overlapping_intevals(intervals);
    ll ans = 0;
    for (int j = 0; j < intervals.size(); j++) {
        ans += intervals[j].second - intervals[j].first + 1;
    }
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}