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

void solve() {
    string s;
    cin >> s;

    sort(range(s));
    int cnt = 0;
    loop(i, s.size()) {
        if(s[i] == s[s.size() - 1]) {
            cnt++;
        }
    }

    cout << string(cnt,s[s.size() - 1] ) << '\n';
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
