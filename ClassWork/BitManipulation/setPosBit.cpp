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

void set_bit(ll &n, ll pos) {
    ll mask = (1LL << pos);
    cout << "Binary of " << n << " before setting " << pos << "th bit: " << bitset<32>(n) << '\n';
    ll temp = n;
    n = (n | mask); 
    cout << "Binary of " << temp << " after setting " << pos << "th bit: " << bitset<32>(n) << '\n';
}
ll n, pos;
void solve() {
    cin >> n >> pos;
    set_bit(n, pos);
    cout << n << '\n';
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
