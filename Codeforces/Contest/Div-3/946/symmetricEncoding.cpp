#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    map<char, int> mp;

    loop(i, n) {
        mp[s[i]]++;
    }
    string r = "";
    for(auto it: mp) {
        r = r + it.first;
    }
    sort(r.begin(), r.end());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r.size(); j++) {
            if(r[j] == s[i]) {
                s[i] = r[r.size() - j - 1];
                break;
            }
        }
    }
    cout << s << '\n';
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
