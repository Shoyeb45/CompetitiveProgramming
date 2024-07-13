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

void solve() {
    int n;
    cin >> n;

    vector<int> ans;
    for(long i = 2; (ll)(i * i) <= n; i++) {
        while(n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    ans.push_back(n);
    loop(i, ans.size())
        cout << ans[i] << ' ';
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
