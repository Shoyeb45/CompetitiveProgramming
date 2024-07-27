#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1];
        prefix[i][b[i - 1] - 'a']++;
        prefix[i][a[i - 1] - 'a']--;
    }

    // loop(i, n + 1) {
    //     if(i >= 1) {
    //         cout << "index: " << i << '\n';
    //         loop(k, 26) {
    //             char io = (char)(k + 'a');
    //             cout << io  << " ";
    //         }
    //         cout << endl;
    //         loop(j, 26) {
    //             cout << prefix[i][j] << " ";
    //         }
    //         cout << "\n";
    //     }

    // }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        loop(i, 26) {
            ans += max(0, prefix[r][i] - prefix[l - 1][i]);
        }
        cout << ans << '\n';
    }
}

int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
