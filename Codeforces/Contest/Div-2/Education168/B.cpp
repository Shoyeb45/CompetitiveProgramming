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
    vector<string> a(2);
    loop(i, 2) {
        cin >> a[i];
    }

    int ans = 0;
    loop(i, 2) {
        loop(j, n) {
            if(a[i][j] == '.') {
                continue;
            } else {
                if(j + 2 < n && a[i][j + 2] == 'x') {
                    int y = j + 1;
                    if(i == 0) {
                        if(a[1][y + 1] == '.' && a[1][y - 1] == '.' && a[0][y] == '.') {
                            ans++;
                        }
                    } else {
                        if(a[0][y + 1] == '.' && a[0][y - 1] == '.' && a[1][y] == '.') {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
