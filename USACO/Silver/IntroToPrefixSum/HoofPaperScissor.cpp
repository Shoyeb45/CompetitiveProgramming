#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;

int winOrLose(int first, int second) {
    if((first == 0 && second == 1) || (first == 1 && second == 2) || (first == 2 && second == 0)) {
        return 1;
    }
    return 0;
}

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        char ch;
        cin >> ch;
        if(ch == 'H') {
            x = 0;
        }
        else if(ch == 'S') {
            x = 1;
        }
        else {
            x = 2;
        }
    }

    // Confirming the input:
    // cout << "Vector: \n";
    // for(auto x: a) {
    //     cout << x << ' ';
    // }
    // cout << "\n";

    vector<vector<ll>> pref(3, vector<ll>(n + 1, 0));

    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] += (pref[i][j - 1] + 1LL * winOrLose(i, a[j - 1]));
        }
    }

    // Confirming the prefix wins:
    // for(int i = 0; i < 3; i++) {
    //     cout << "For " << i << '\n';
    //     for(int j = 1; j < n + 1; j++) {
    //         cout << pref[i][j] << " ";
    //     }
    //     cout << "\n\n";
    // }
    ll ans = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 1; j <= n; j++) {
            int first = 0, second = 0;
            if(i == 0) {
                first = 1, second = 2;
            }
            else if(i == 1) {
                first = 0, second = 2;
            } 
            else {
                first = 0, second = 1;
            }

            ans = max(ans, (ll)(pref[i][j] + (pref[first].back() - pref[first][j])));
            ans = max(ans, (ll)(pref[i][j] + (pref[second].back() - pref[second][j])));
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
