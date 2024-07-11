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

int n, m, k;
void solve() {
    cin >> n >> m >> k;
    vector<int> ans;
    for(int i = n; i >= 1; i--) {
        ans.push_back(i);
    }
    loop(i, ans.size()) {
        if(ans[i] == m) {
            sort(ans.begin() + i, ans.end());
            break;
        }
    }

    loop(i, ans.size())
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
