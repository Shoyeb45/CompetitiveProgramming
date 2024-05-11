#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= n; i++)  cin >> b[i];
    
    vector<int> occurence_a(2 *n + 1);
    vector<int> occurence_b(2 *n + 1);
    int start = 1;

    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            occurence_a[a[i - 1]] = max(occurence_a[a[i - 1]], i - start);
            start = i;
        }
    }
    occurence_a[a[n]] = max(occurence_a[a[n]], n - start + 1);

    start  = 1;
    for(int i = 2; i <= n; i++) {
        if(b[i] != b[i - 1]) {
            occurence_b[b[i - 1]] = max(occurence_b[b[i - 1]], i - start);
            start = i;
        }
    }
    occurence_b[b[n]] = max(occurence_b[b[n]], n - start + 1);

    int ans = 0;
    for(int i = 1; i <= 2*n; i++) {
        ans = max(ans, occurence_a[i] + occurence_b[i]);
    }
    cout << ans << '\n';
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
