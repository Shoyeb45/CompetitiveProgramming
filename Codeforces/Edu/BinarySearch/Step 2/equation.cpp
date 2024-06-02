#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(double x, double c) {
    double cmp = x * x + sqrt(x);
    // cout << "Cmpr: " << cmp << '\n';
    return (cmp <= c);
}
void solve() {
    double c;
    cin >> c;

    double low = 0, high = 1e10;
    double ans = 0;
    int iteration = 1000;
    while(iteration--) {
        double mid = low + (high - low)/2;
        if(check(mid, c)) {
            ans = mid;
            low = mid + 1;2
        // cout << "MID: " << mid << '\n';
        } else {
            high = mid - 1;
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
