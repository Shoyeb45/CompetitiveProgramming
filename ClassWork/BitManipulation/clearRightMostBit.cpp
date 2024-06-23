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

void clear_right_most_bit(ll &n) {
    cout << n << ": " <<  bitset<32>(n) << '\n';
    ll temp = n;
    n = (n & (n - 1));
    cout << temp << " after clearing right most set bit: " << bitset<32>(n) << " = " << n;
}
ll n;
void solve() {
    cin >> n;
    clear_right_most_bit(n);
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
