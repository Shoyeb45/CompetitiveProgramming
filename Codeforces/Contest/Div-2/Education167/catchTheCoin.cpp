#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n;
void solve() {
    cin >> n;
    while(n--) {
        int x, y;
        cin >> x >> y;
        if(y > 0) {
            cout << "YES\n";
        } else {
            if(0 - y <= 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
