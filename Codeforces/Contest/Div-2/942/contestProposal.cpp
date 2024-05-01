#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    loop(i, n)  cin >> a[i];
    loop(i, n)  cin >> b[i];

    int ans = INT_MIN;
    loop(i, n) {
        int count = 0;    
        if(a[i] > b[i]) {
            int j = i;
            while(j < n && a[i] > b[j]) {
                count++;
                j++;
            }
            ans = max(ans, count);
        }
    }

    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
