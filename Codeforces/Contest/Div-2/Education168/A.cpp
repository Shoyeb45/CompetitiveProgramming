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

    if(s.size() == 1) {
        if(s[0] == 'z') {
            cout << "zy" << '\n';
        } else {
            string ans = "";
            ans += s[0];
            ans += (s[0] + 1);
            cout << ans << '\n';
        }
        return;
    }    

    string temps = "";
    char c = 'c';
    int idx = -1;
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1]) {
            if(s[i] == 'z') {
                c = 'y';
            } else {
                c = s[i] + 1;
            }
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        char c = 'c';
        if(s.back() == 'z') {
            c = 'y';
        } else {
            c = s.back() + 1;
        }
        cout << (s + c) << '\n';
        return;
    }
    for(int i = 0; i <= idx; i++) {
        temps += s[i];
    }
    temps += c;
    for(int i = idx + 1; i < s.size(); i++) {
        temps += s[i];
    }
    cout << temps << '\n';
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
