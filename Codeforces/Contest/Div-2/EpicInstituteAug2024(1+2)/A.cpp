#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, m, k;
void solve() {
    cin >> n >> m >> k;

    if(max(n - 1, m - 1) < k) {
        cout << n * m << "\n";
    } else {
        ll ans = 0;
        ll cnt = 0;
        for(int i = 1; i <= min(k, n); i++) {
            for(int j = 1; j <= min(k, m); j++) {
                int x = i + k, y = j + k;
                    if(x <= n && y <= m) {
                        ans += 1;
                        cnt += 4;
                        int s = 1;
                        x += k;
                        y += k;
                        while(x <= n && y <= m) {
                            cnt += s++;
                            x += k;
                            y += k;
                        }
                    } else if(x <= n) {
                        ans += 1;
                        while(x <= n) {
                            cnt += 2;
                            x += k;
                        }
                    } else if(y <= m) {
                        while(y <= m) {
                            cnt += 2;
                            y += k;
                        }
                        ans += 1;

                    }
            }
        }
            ans += (n * m - cnt);
            cout << ans << '\n';
    }
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
