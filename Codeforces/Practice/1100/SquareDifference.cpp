#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll a, b;
bool isPrime(ll rem) {
    if(rem <= 1) {
        return false;
    }

    for(ll i = 2; i * i <= rem; i++) {
        if(rem % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> a >> b;
    if(a - b != 1) {
        cout << "NO\n";
        return;
    }

    ll rem = a + b;

    cout << (isPrime(rem) ? "YES\n": "NO\n");
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