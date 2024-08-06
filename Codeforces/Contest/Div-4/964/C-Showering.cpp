#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m, s;
void solve() {
    cin >> n >> s >> m;

    vector<pair<int, int>> intervals;

    loop(i, n) {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y});
    }

    int strt = 0;

    loop(i, n) {
        if(intervals[i].first - strt >= s) {
            cout << "YES\n";
            return;
        } 
        strt = intervals[i].second;
    }

    if(m - strt >= s) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
