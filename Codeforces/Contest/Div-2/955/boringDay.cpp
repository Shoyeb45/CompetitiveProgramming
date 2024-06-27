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

int n, l, r;
vector<ll> a;
  
void solve() {
    cin >> n >> l >> r;
    a.resize(n);
    loop(i, n)
        cin >> a[i];
    
    ll curr = 0, cnt = 0, j = 0;
    loop(i, n) {
        curr += a[i];
        while(curr > r && j <= i) {
            curr -= a[j];
            j++;
        }
        if(curr >= l && curr <= r) {
            cnt++;
            curr = 0;
            j = i + 1;
        }
    }
    cout << cnt << '\n';
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
