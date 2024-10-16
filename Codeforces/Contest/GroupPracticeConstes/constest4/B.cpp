#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

bool isPerfectSq(int x) {
    int sq = (int) sqrt(x);
    return sq * sq == x;
}
void solve() {
    cout << isPerfectSq(105) << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}