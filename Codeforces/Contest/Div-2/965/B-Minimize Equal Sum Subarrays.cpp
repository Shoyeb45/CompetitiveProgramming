#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<int> p(n), ans(n);

    loop(i, n) {
        cin >> p[i];
    }
    ans[n - 1] = p[0];
    
    for(int i = 1; i <= n - 1; i++) {
        ans[i - 1] = p[i];
    }
    
    loop(i, n) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
