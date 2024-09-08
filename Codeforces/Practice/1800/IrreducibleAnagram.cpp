#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

string s;
void solve() {
    int q;
    cin >> s;
    cin >> q;
    int n = s.size();

    vector<vector<int>> pref(26, vector<int> (n + 1, 0)); 

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += (pref[i][j - 1] + ((char)('a' + i) == s[j - 1] ? 1 : 0));
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int dist = 0;
        for(int i = 0; i < 26; i++) {
            dist += (pref[i][r] - pref[i][l - 1] > 0 ? 1: 0);
        }

        if((l == r) || (s[r - 1] != s[l - 1]) || (dist >= 3)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
