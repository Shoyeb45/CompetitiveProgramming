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

// First way
int no_of_set_bits(ll n) {
    cout << "Binary of " << n << " : " << bitset<32>(n) << '\n';
    int ans = 0;
    while(n >= 1) {
        if((n & 1) == 1) 
            ans++;
        n = (n >> 1);
    }
    return ans;
}

// Second way
int no_of_set_bits_2(ll n) {
    int ans = 0;
    while(n != 0) {
        n = (n & (n - 1));
        ans++;
    }
    return ans;
}
ll n;
void solve() {
    cin >> n;
    cout << no_of_set_bits(n) << '\n';
    // Second method:
    cout << no_of_set_bits_2(n) << '\n';
    
    // in-buit function:
    cout << __builtin_popcount(n) << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
