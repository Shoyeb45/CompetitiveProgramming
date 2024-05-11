#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    set<char> typableChar;
    loop(i, k) {
        char x; cin >> x;
        typableChar.insert(x);
    }

    ll ans = 0;
    if(k == 26) {
        ans = 1LL * n * 1LL * (n + 1)/2;
    } else {
            int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(typableChar.find(s[i]) == typableChar.end()) {
                ans += 1LL * cnt * 1LL * (cnt + 1)/2;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans += 1LL * cnt * 1LL * (cnt + 1)/2;
    }

    cout << ans << '\n';
    return 0;
}
