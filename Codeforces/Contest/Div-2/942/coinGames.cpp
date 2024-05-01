#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt_u = 0;
    loop(i, n) {
        cnt_u += (s[i] == 'U');
    }
    
    if(cnt_u % 2 == 0) 
        cout << "NO\n";
    else
        cout << "YES\n";
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
