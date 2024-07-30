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
    unordered_map<char, int> mp1, mp2;
    loop(i, n) {
        mp1[s[i]]++;
    }

    int ans = INT_MIN, a = 0;
    loop(i, n) {
        if(mp2.find(s[i]) == mp2.end()) {
            mp2[s[i]]++;
            a++;
        }
        mp1[s[i]]--;
        int b = 0;
        for(auto it: mp1) {
            if(it.second != 0) {
                b++;
            }
        }
        ans = max(ans, b + a);
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
