#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

string s, t;
void solve() {
    cin >> s >> t;

    int i = 0, j = 0;
    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) {
            if(j == t.size() - 1) {
                j++;
                continue;
            }
            int idx = 0;
            for(int k = i + 1; k < s.size(); k++) {
                if(s[k] == t[j + 1]) {
                    idx = k;
                }
            }

            for(int k = i + 1; k < idx; k++) {
                if(s[k] == t[j]) {
                    cout << "NO\n";
                    return;
                }
            }
            j++, i++;
        } else {
            i++;

        }
    }
    cout << "YES\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
