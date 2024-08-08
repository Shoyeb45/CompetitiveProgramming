#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<ll> odd, even;
    loop(i, n) {
        ll x;
        cin >> x;
        if((x & 1) == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }

    if(odd.empty() || even.empty()) {
        cout << 0 << '\n';
    } else {
        int ans = 0;
        ll sum = *max_element(range(odd));
        sort(range(even));
        int i = 0;
        for(i = 0; i < even.size(); i++) {
            if(sum > even[i]) {
                sum += even[i];
                ans++;
            } else {
                break;
            }
        }
        if(i != even.size()) {
            ans += 2;
            ans += even.size() - i - 1;
        }

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
