#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(int mid, int x, int y, int n) {
    if(mid < min(x, y))
        return false;
    int time = mid - min(x, y);
    int cnt = 1;
    int rem = 0;
    while(time >= max(x, y)) {
        cnt += (1 + max(x, y)/min(x, y));
        time -= max(x, y);
        rem += (max(x, y) % min(x, y));
    }

    cnt += (rem/min(x, y));
    return cnt >= n;
}
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int low = 1, high = max(x, y) * n;
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(check(mid, x, y, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
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
