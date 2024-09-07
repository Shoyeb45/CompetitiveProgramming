#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
void solve() {
    cin >> n >> q;
    vector<vector<ll>> pref(3, vector<ll>(n + 1, 0));

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        x--;
        pref[x][i]++;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < 3; i++) {
            if(i == 2) {
                cout << pref[i][b] - pref[i][a - 1];
            } 
            else {
                cout << pref[i][b] - pref[i][a - 1] << " ";
            }
        }
        cout << "\n";
    }

}

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
