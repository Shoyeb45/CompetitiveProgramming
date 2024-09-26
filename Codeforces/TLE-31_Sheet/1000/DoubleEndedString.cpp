#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

string a, b;
void solve() {
    cin >> a >> b;

    int ans = a.size() + b.size();
    int i = 0, j = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                int x, y;
                for(x = i, y = j; x < a.size() && y < b.size(); x++, y++) {
                    if(a[x] != b[y]) {
                        break;
                    }
                }
                x--, y--;
                ans = min(ans, ((int)b.size() - (y - j + 1)) + ((int)a.size() - (x - i + 1)));
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