#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
string s;
void solve() {
    cin >> n >> k >> s;

    int low = 0, high = k - 1;
    int w = 0, b = 0;
    for(int i = 0; i <= high; i++) {
        if(s[i] == 'W') {
            w++;
        }
        else {
            b++;
        }
    }
    int ans = INT_MAX;
    while(high < n) {
        ans = min(ans, w);
        if(s[low] == 'W') {
            w--;
        }
        else {
            b--;
        }
        low++, high++;
        if(high >= n) {
            break;
        }

        if(s[high] == 'W') {
            w++;
        }
        else {
            b++;
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