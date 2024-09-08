#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int m, n;
vector<ll> t, y, z;

bool f(ll time, vector<ll> &ans) {
    ll res = m;
    vector<ll> temp(n);
    for(int i = 0; i < n; i++) {
        ll cycle = t[i] * z[i] + y[i];
        ll round = (time) / (cycle);
        ll timeLeft = time % cycle;
        ll moreBallon = min(timeLeft / t[i], z[i]);

        ll totalBallon = round * z[i] + moreBallon;
        temp[i] = min(totalBallon, res);
        res -= min(totalBallon, res);
    }
    if(res) {
        return 0;
    }
    ans = temp;
    return 1;
}
void solve() {
    cin >> m >> n;
    t.resize(n), y.resize(n), z.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> y[i] >> z[i];
    }    

    ll minTime = -1;
    ll low = 0, high = 1e10;
    vector<ll> numOfBallons(n);
    
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(f(mid, numOfBallons)) {
            minTime = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << minTime << '\n';

    for(auto x: numOfBallons) {
        cout << x << ' ';
    }
    cout << "\n";
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
