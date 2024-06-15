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
int n, t;
vector<int> a;

void solve() {
    cin >> n >> t;
    a.resize(n);
    
    loop(i, n)
        cin >> a[i];
    
    ll sum = t + a[0]; 
    cout << sum << '\n';
    for(int i = 1; i < n; i++) {
        if(a[i] <= sum) {
            sum += t;
            cout << sum << '\n';
        } else {
            sum += (a[i] - sum) + t ;
            cout << sum << '\n';
        }
    }
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
