#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
string s;
void solve() {
    cin >> n >> s;
    int ans = 1;

    int i = 0; 
    while(i < n - 1) {
        int temp = 1;
        if(s[i] == s[i + 1]) {
            while(i < n - 1 && s[i] == s[i + 1]) {
                i++, temp++;
            }
        }
        else {
            i++;
        }
        
        ans = max(ans, temp);
    }
    cout << ans + 1 << '\n';
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
