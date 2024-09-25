#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout << "x : " << x << '\n';
typedef long long ll;
const ll mod = 1000000007;

ll a, b;
void solve() {
    cin >> a >> b;

    ll ans = 0;
    while(a != b) {
        if(a > b) {
            if(a % b != 0) {
                cout << "-1" << "\n";
                return;
            } 

            ll c = a / b;
            if(c % 8 == 0) {
                ans++;
                a /= 8;
                continue;
            }
            else if(c % 4 == 0) {
                ans++;
                a /= 4;
                continue;
            }
            else if(c % 2 == 0) {
                ans++;
                a /= 2;
                continue;
            }
            cout << "-1" << "\n";
            return;
        }
        else {
            if(b % a != 0) {
                cout << "-1" << "\n";
                return;
            }
            // cout << a << '\n';
            if(a * 8 <= b) {
                ans++;
                a *= 8;
                continue;
            }
            else if(a * 4 <= b) {
                ans++;
                a *= 4;
                continue;
            }
            else if(a * 2 <= b) {
                ans++;
                a *= 2;
                continue;
            }
            cout << "-1" << "\n";
            return;
        }
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