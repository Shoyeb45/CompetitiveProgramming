#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int l, r, L, R;
void solve() {
    cin >> l >> r >> L >> R;

    if(r < L || R < l) {
        cout << 1 << "\n";
        return;
    }

    if(l == L && r == R) {
        cout << r - l << '\n';
    } else {
        if((l == L && r < R) || (r == R &&  l > L)) {
            cout << r - l + 1 << '\n';
        } else if((l == L && R < r) || (R == r && L > l)) {
            cout << R - L + 1 << '\n';
        } else if(r == L || R == l) {
            cout << 2 << '\n';
        }
        else if((l > L && r < R) || (L > l && R < r)) {
            cout << min(R- L + 2, r - l + 2) << '\n';
        } else if((L < l && R < r)) {
            cout << R - l + 2 << '\n';
        } else if((l < L && r < R)) {
            cout << r - L + 2 << '\n';
        } 
    }
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
