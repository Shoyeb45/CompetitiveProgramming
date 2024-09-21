#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, x, y;
void solve() {
    cin >> n >> x >> y;
    ll time = (n + x - 1) / x;
    ll fru = time * y;

    if(fru >= n) {
        cout << time << '\n';
    }
    else {
        ll rem = n - fru;
        cout << time + (rem + y - 1) / y << '\n';
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
