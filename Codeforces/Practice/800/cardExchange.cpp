#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    loop(i, n)  cin >> a[i];
    map<int, int> m;
    loop(i, n)  m[a[i]]++;

    if(k > n) {
        cout << n << endl;
        return;
    }
    for(auto it: m) {
        if(it.second >= k) {
            cout << k - 1 << endl;
            return;
        }
    }
    cout << n << endl;
    return;
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
