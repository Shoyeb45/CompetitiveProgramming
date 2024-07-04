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

int n, m;
void solveBS() {
    // Binary Search Solution
    cin >> n >> m;
    vector<int> a(n), b(m);
    loop(i, n)
        cin >> a[i];
    loop(j, m) 
        cin >> b[j];
    
    ll ans = 0;
    loop(i, n) {
        ans += (upper_bound(range(b), a[i]) - lower_bound(range(b), a[i]));
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solveBS();
    }
    
    return 0;
}
