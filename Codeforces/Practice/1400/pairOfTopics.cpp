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
vector<ll> a;
vector<ll> b;

int lb(vector<ll> &c, int low, int high, int target) {
    int ans = c.size();
    while(low <= high) { 
        int mid = (low + high) / 2;    
        if(c[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } 
    return ans;
}
void solve() {
    cin >> n;
    a.resize(n);    
    b.resize(n);

    loop(i, n)
        cin >> a[i];
    loop(i, n)
        cin >> b[i];
    
    vector<ll> c(n);
    loop(i, n) {
        c[i] = a[i] - b[i];
    }
    sort(range(c));

    ll ans = 0;
    loop(i, n) {
        if(c[i] <= 0)
            continue;
       int j = lb(c, 0, n - 1, 1 - c[i]);
       ans += i - j;
    }
    cout << ans << '\n';
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
