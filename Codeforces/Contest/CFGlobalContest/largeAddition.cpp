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

    if(s.back() == '9') {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == '0') {
            cout << "NO\n";
            return;
        }
    }

    int carry = 0;
    int x = (s[0] - '0') * 10 + (s[1] - '0');
    // cout << x << "\n\n";
    for(int i = s.size() - 1; i >= 0; i--) {
        int curr = (s[i] - '0');
        int ans = 0;
        // cout << "Curr " << curr << '\n';
        // cout << "carry " << carry << '\n';
        for(int i = 5; i <= 9; i++) {
                bool check = 0;
            for(int j = 5; j <= 9; j++) {
                int temp = i + j;
                if(((temp + carry) % 10) == (curr)) {
                    // cout << "i : " << i << " j: " << j << '\n';
                    ans = temp;

                    carry = temp/10;
                    check = 1;
                    break;
                }
            }
            if(check)
                break;
        }
        // cout << "digit: " << (int)(log10(ans)) + 1  << '\n';
        // cout << "ans: " << ans << "\n\n";
        if(i == 0) {
            if(((int)(log10(ans)) + 1 )== 2) {
                cout << "NO\n";
                return;
            } 
        }
        if(!ans) {
            cout << "NO\n";
            return;
        }
        if(ans == x) {
            cout << "YES\n";
            return;
        }
    }
    cout << "YES\n";
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
