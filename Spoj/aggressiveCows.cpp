#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(vector<int> &a, int c, ll mid) {
    int cnt = 1;
    int last_cow = a[0];
    for(int  i = 1; i < a.size(); i++) {
        if(a[i] - last_cow >= mid) {
            cnt++;
            last_cow = a[i];
        }
    }
    return cnt >= c;
}
void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> l(n);
    loop(i, n)
        cin >> l[i];
    
    sort(l.begin(), l.end());

    ll ans = 0;
    ll low = 0, high = 1e9;

    while(low <= high) {
        ll mid = low + (high - low)/2;
        // cout << mid << '\n';
        if(check(l, c, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
