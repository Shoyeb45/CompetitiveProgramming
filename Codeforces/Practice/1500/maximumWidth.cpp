#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;   cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;
    vector<int> first_occur(m);
    vector<int> last_occur(m);
    
    for(int i = 0, j = 0; i < n; i++) {
        if(s[i] == t[j]){
            first_occur[j] = i;
            j++;
        }
    }

    for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
        if(s[i] == t[j]) {
            last_occur[j] = i;
            j--;
        }
    }

    int ans = 0;
    for(int i = 1; i < m; i++) {
        ans = max(ans, last_occur[i] - first_occur[i - 1]);
    }

    cout << ans << '\n';
    return 0;
}
