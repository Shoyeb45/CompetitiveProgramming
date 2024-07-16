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
    string new_s;

    loop(i, n - 1) {
        if(s[i] == '1') {
             new_s += '1';
        } else {
            while(s[i] == s[i + 1] && i < n - 1) {
                i++;
            }
            new_s += '0';
        }
    }
    
    if(s[n - 1] == '1') {
        new_s += '1';
    } else {
        if(new_s.back() == '1' || new_s.empty()) {
            new_s += '0';
        }
    }

    int ones = 0, zero = 0;
    loop(i, new_s.size()) {
        if(new_s[i] == '1') 
            ones++;
        else 
            zero++;
    }

    if(ones > zero) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
