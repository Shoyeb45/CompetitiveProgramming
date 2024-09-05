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

    vector<string> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<int> ans;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 4; j++) {
            if(a[i][j] == '#') {
                ans.push_back(j + 1);
            }
        }
    }

    for(auto x: ans) {
        cout << x << " ";
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
