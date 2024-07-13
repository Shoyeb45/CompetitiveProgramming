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

int n;
void solve() {
    cin >> n;
    vector<int> ans;
    ll p = 1;
    for(int i = 2; i < n; i++) {
        if(__gcd(n, i) == 1) {
            ans.push_back(i);
            p = ((p * i) % n);
        }
    }
    p %= n;
    vector<int> a = {1};
    loop(i, ans.size()) {
        if(ans[i] != p) {
            a.push_back(ans[i]);
        }
    }
    cout << a.size() << "\n";
    loop(i, a.size())
        cout << a[i] << ' ';
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
