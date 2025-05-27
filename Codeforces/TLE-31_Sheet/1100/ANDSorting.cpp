#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);

    for (auto &x: a) {
        cin >> x;
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            if (ans == -1) {
                ans = a[i];
            } else {
                ans &= a[i];
            }
        }
    }

    cout << ans << "\n";
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