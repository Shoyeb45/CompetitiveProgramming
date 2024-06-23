#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

// auto init = []() { 
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();

void solve() {
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> ind(m);
    loop(i, m)
        cin >> ind[i];
    string c;
    cin >> c;

    sort(range(c));
    sort(range(ind));

    int prev = -1, k = 0;
    for(int i = 0; i < m; i++) {
        if(prev != ind[i]) {
            s[ind[i] - 1] = c[k++];
            prev = ind[i];
        } 
    }
    cout << s << '\n';
}

int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
