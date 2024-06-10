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

bool is_zero(string s) {
    loop(i, s.size() - 1) {
        if(s[i] == '0')
            return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    bool flag1 = is_zero(s);
    if(s[0] == '1' && s.back() != '9' && flag1) 
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
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
