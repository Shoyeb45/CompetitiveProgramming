#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
vector<int> a;

void solve() {

    cin >> n >> k;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }
    sort(range(a));
    reverse(range(a));

    int ans = 0;
    
    loop(i, n) {
        if(i % 2 == 0) {
            ans += a[i];
        } 
        else {
            int diff = a[i - 1] - a[i];
            if(diff <= k) {
                a[i] = a[i - 1];
                k -= diff;
            } 
            else {
                a[i] += k;
                k = 0;
            }

            ans -= a[i];
        }
    }

    cout << ans << '\n';
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
