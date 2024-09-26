#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, k, beauty, sum;
void solve() {
    cin >> n >> k >> beauty >> sum;

    
    vector<ll> ans;
    for(int i = 0; i < n; i++) {
        ll lb = k * beauty, ub = k * (beauty + 1) - 1;
        if(sum >= lb && sum <= ub) {
            ans.push_back(sum);
            beauty = 0;
            sum = 0;
        }
        else if(sum >= ub) {
            ans.push_back(ub);
            beauty = 0;
            sum -= ub;
        }
        else if(sum < lb) {
            cout << -1 << "\n";
            return;
        }
        else if(sum == 0) {
            ans.push_back(sum);
        }

    }

    if(sum > 0) {
        cout << -1 << '\n';
        return;
    }

    for(auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
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