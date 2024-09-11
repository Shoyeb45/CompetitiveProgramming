#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<string> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    int ans = 0;
    for(int i = 0; i < 8; i++) {
        int temp = 0;
        for(auto x: a) {
            if(x[i] == '1') {
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";
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
