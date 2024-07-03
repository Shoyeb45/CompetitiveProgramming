#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;

void solve() {
    cin >> n;
    vector<vector<int>> a(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }    

    int ans = 0;
    cout << "conn\n";
    for(int i = 1; i <= n; i++) {
        loop(j, a[i].size())
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    for(int i = 1; i <= n; i++) {
        if(a[i].empty())
            ans++;
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
