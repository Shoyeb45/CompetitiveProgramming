#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n) {
        cin >> a[i];
    }

    ll neg_sum = 0;
    int i = 0;
    while(i < n) {
        if(a[i] < 0) {
            neg_sum += a[i++];
        } else {
            break;
        }
    }

    ll ans = 0;
    while(i < n)
        ans = abs(ans + a[i++]);
    
    cout << ans + abs(neg_sum) << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
