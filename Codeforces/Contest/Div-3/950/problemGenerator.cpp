#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    map<char, int> mp;
    char check = 'A';
    while(check <= 'G') {
        mp[check] = 0;
        check += 1;
    }
    // for(auto it: mp) {
    //     cout << it.first << ' ' << it.second << '\n';
    // }
    loop(i, n) {
        mp[s[i]]++;
    }
    int ans = 0;
    
    for(auto it: mp) {
        if(it.second < m) {
            ans += (m - it.second);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
