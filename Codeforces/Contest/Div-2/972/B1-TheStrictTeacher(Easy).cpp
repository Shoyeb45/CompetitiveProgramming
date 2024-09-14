#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m, q;
int t1, t2;
int d;
void solve() {
    cin >> n >> m >> q;
    cin >> t1 >> t2;
    int temp1 = min(t1, t2);
    int temp2 = max(t1, t2);
    t1 = temp1;
    t2 = temp2;

    cin >> d;

    int ans = 0;

    if(d > t1 && d < t2) {
        int mid = ((t1 + 1) + (t2 - 1)) / 2;
        ans += abs(d - mid);
        if(d > mid) {
            d -= ans;
        }
        else {
            d += ans;
        }
        t1 += ans;
        t2 -= ans;
        ans += min(t2 - d, d - t1);
    }
    else if(d < t1){
        ans += (d - 1);
        t1 -= ans;
        ans += (t1 - 1);
    }
    else {
        ans += (n - d);
        t2 += ans;
        ans += (n - t2);
    }

    cout << ans << '\n';
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
