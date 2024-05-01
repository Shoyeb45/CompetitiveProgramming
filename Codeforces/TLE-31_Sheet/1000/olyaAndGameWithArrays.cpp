#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> smallest;
    vector<int> smallest2;
    int temp = n;
    while(n--) {
        int m; cin >> m;
        vector<int> a(m);
        loop(i, m)  cin >> a[i];
        
        sort(a.begin(), a.end());

        smallest.push_back(a[0]);
        smallest2.push_back(a[1]);
    }

    sort(smallest.begin(), smallest.end());
    sort(smallest2.begin(), smallest2.end());

    ll ans = smallest[0];
    for(int i = 1; i < temp; i++) {
        ans += (smallest2[i]);
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
