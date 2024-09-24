#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<ll> a;

    ll ans = 0;
    ll neg = 0;
    ll zero = 0;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
       
        if(x < 0) {
            neg++;
        }
        else if(x == 0) {
            zero++;
        }
        a.push_back(x);
    }

    // even numbers of negative
    if(neg % 2 == 0) {
        
        for(auto x: a) {
            if(x < 0) {
                ans += -1 - x;
            }
            else if(x == 0) {
                ans++;
            }
            else {
                ans += x - 1;
            }
        }
    }  
    else {
        sort(range(a));

        if(zero >= 1) {
            ans += zero;
            for(auto x: a) {
                if(x < 0) {
                    ans += -1 - x;
                }
                else if(x == 0) {
                    continue;
                }
                else {
                    ans += x - 1;
                }
            }
        }
        else {

            for(auto x: a) {
                if(x < 0) {
                    ans += -1 - x;
                }
                else {
                    ans += x - 1;
                }
            }
            ans += 2;
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
