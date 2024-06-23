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

void clear_bit(ll &n, ll pos) {
    ll mask = (1LL << pos);   // 1.
    cout << "Left shifting 1 - " << pos << " times: " << bitset<32>(mask) << '\n';
    mask = (~mask);  // 2.
    cout << "Flipping all the bits: "  << bitset<32>(mask) << '\n';

    cout << n << " before clearing " << pos << "th bit: " << bitset<32>(n) << '\n';
    ll temp = n;
    n = (n & mask); // 3.
    cout <<temp << " after clearing " << pos << "the bit: "  << n << '\n' << "Binary: " << bitset<32>(n); 
}

ll n, pos;
void solve() {
    cin >> n >> pos;
    clear_bit(n, pos);
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
