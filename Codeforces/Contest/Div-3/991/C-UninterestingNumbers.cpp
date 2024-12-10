#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// int n;
string s;
void solve() {
    cin >> s;

    ll sum = 0;
    int cnt2 = 0, cnt3 = 0;

    for (auto ch : s) {
        cnt2 += (ch == '2'), cnt3 += (ch == '3');
        sum += (ch - '0');
    }

    if (sum % 9 == 0) {
        cout << "YES\n";
        return;
    }
    // debug("cnt2", cnt2, "cnt3", cnt3);

    for (ll num = ((sum + 8) / 9) * 9; num <= sum + 2 * (cnt2 + 3 * cnt3) ; num += 9) {
        ll req = num - sum;
        if (req % 2 == 0) {
            for (int i = 0; i <= cnt3; i++) {
                int x = req / 2 - 3 * i;
                if (x >= 0 && x <= cnt2) {
                    // debug("x", x, "i", i);
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    // cout << sum << "\n";
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}