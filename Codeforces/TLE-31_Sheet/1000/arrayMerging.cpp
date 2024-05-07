#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    loop(i, n) {
        int a;
        cin >> a;
        m[a]++;
    }

    loop(i, n) {
        int a;
        cin >> a;
        m[a]++;
    }
    int ans = 0;
    for(auto it: m) {
        ans = max(ans, it.second);
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
