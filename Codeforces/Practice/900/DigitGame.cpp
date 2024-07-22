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
string s;
void solve() {
    cin >> n >> s;
    int cnt = 0;
    if((n & 1) == 1) {
        for(int i = 0; i < n; i += 2) {
            if((s[i] - '0') % 2 == 1) 
                cnt++;
        }

        if(cnt >= 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    } else {
        for(int i = 1; i < n; i += 2) {
            if((s[i] - '0') % 2 == 0) 
                cnt++;
        }

        if(cnt >= 1) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
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
