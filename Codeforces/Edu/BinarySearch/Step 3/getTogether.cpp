#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(vector<pair<int, int>> &vp, double mid) {
    double mx = INT_MIN, mn = INT_MAX;
    for(int i = 0; i < vp.size(); i++) {
        double left = vp[i].first - mid * vp[i].second;
        double right = vp[i].first + mid * vp[i].second;
        mx = max(mx, left);
        mn = min(mn, right);
        // cout << "Left: " << left << " Right: " << right << '\n';
    }
    // cout << "Max: " << mx << " Min: " << mn << '\n';
    return mn - mx >= 0;
} 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    loop(i, n) {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    double low = 0, high = 2e9;
    double ans = high;
    int iteration = 100;
    while(iteration--) {
        double mid = low + (high - low)/2;
        if(check(vp, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
