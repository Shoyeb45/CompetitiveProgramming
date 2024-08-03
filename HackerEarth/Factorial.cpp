#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;


auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


ll fact[(int)1e5 + 1] = {0};

ll calcFacto(int n) {
    if(n == 1 || n == 0) {
        return 1;
    }

    ll ans = (n * calcFacto(n - 1))% mod;
    fact[n] = ans % mod;
    return ans % mod;
}

void solve() {
    int n;
    cin >> n;
    
    cout << fact[n] << '\n';
}

int main() {
    calcFacto(1e5);
    int tt;
    // tt = 1;
    cin >> tt;

    fact[1] = fact[0] = 1;
    while (tt--) {
        solve();
    }
    
    return 0;
}
