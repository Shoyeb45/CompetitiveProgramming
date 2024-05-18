#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    if(p3 % 2 == 1 && (p1 + p2) % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    if(p3 % 2 == 1) {
        int ans = min(p1, p2) 
    }
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
