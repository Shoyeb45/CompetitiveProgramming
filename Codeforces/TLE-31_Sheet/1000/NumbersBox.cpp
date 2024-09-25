#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    ll posCnt = 0, sum = 0;
    int mn = INT_MAX;
    for(auto &x: a) {
        for(auto &y: x) {
            cin >> y;
            posCnt += (y < 0);
            mn = min(mn, abs(y));
            sum += abs(y);
        }
    }    

    if(posCnt % 2 == 1) {
        sum -= 2 * mn;
    }
    cout << sum << "\n";
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