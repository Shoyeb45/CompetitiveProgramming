#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    ll ans = 0;

    string s;

    while (cin >> s) {
        int n = s.size();
        // ll mx_jolt = 0;
        // Part 1
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         ll tmp = (s[i] - '0') * 10 + s[j] - '0';
        //         mx_jolt = max(mx_jolt, tmp);
        //     }
        // }

        int wndo_size = n - 11; 
        cout << wndo_size << " " << n << "\n";
        string mx_jolt = "";

        for (int i = 0; i < n; ) {
            int mx = s[i] - '0';
            int idx = i;
            for (int j = i + 1; j < wndo_size + i; j++) {
                int dig = s[j] - '0';
                if (dig > mx) {
                    mx = dig;
                    idx = j;
                }
            }
            mx_jolt += s[idx];
            if (mx_jolt.size() == 12) break;
            i = idx + 1;
            int len = n - i;
            int taken_len = mx_jolt.size();
            wndo_size = len - (11 - taken_len);
        }
        cout << mx_jolt << "\n";
        // Part 2 
        ans += stoll(mx_jolt);
        
    }
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}