#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void solve() {
    string s;
    cin >> s;
    int i = 0;
    bool flag = 1;
    while(i < s.size()) {
        if(i + 2 < s.size() && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            i += 3;
            if(!flag) {
                flag = 1;
                cout << ' ';
            }
            continue;
        } else {
            flag = 0;
            cout << s[i++];
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
