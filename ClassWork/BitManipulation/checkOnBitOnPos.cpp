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

// By left shift
bool is_bit_on(ll n, ll pos) {
    ll mask = (1LL << pos);
    return (mask & n) != 0;
}

// By right shift
bool is_bit_on_2(ll n, ll pos) {
    ll mask = (n >> pos);
    return (mask & 1) == 1;
}

ll n, i;
void solve() {
    cin >> n >> i;
    cout << "Right shift: " << (is_bit_on_2(n, i) ? "On": "Off") << '\n';
    cout << "Left shift: " << (is_bit_on(n, i) ? "On": "Off") << '\n';

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
