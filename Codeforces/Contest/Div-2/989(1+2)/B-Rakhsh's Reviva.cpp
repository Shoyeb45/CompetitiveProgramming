#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;
string s;

bool ok() {
    int cntZero = 0, cntOne = 0;

    for (int i = 0; i < m; i++) {
        if (s[i] == '0') {
            cntZero++;
        }
        else {
            cntOne++;
        }
    }

    if (cntZero == m) {
        return false;
    }
    for (int l = 0, r = m; r < s.size(); r++, l++) {
        if (s[l] == '0') {
            cntZero--;
        }
        else {
            cntOne--;
        }

        if (s[r] == '0') {
            cntZero++;
        } 
        else {
            cntOne++;
        }
        if (cntZero == m) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m >> k >> s;


    if (ok()) {
        cout << 0 << "\n";
        return;
    }
    // if (k == 1) {
    //     cout << count(range(s), '0') << "\n";
    //     return;
    // }

    int ans = 0;
    int cntOne = 0, cntZero = 0, lastIdx = 0;

    for (int i = 0; i < m; i++) {
        if (s[i] == '0') {
            cntZero++;
            lastIdx = i;
        }
        else {
            cntOne++;
        }
    }

    if (cntZero == m) {
        for (int i = lastIdx; i <= min (lastIdx + k - 1, n - 1); i++) {
            if (s[i] == '0' && i >= 0 && i < m) {
                cntZero--, cntOne++;
            }
            s[i] = '1';
        }
        ans++;
    }
    // cout << s << "\n";
        // debug("0", cntZero, "1", cntOne);
    for (int l = 0, r = m; r < s.size(); r++, l++) {
        int tempIdx = -1;

        if (s[l] == '0') {
            cntZero--;
        }
        else {
            cntOne--;
        }

        if (s[r] == '0') {
            lastIdx = r;
            cntZero++;
        } 
        else {
            cntOne++;
        }
        // debug("0", cntZero, "1", cntOne);
        if (cntZero == m) {
            for (int i = lastIdx; i <= min (lastIdx + k - 1, n - 1); i++) {
                if (s[i] == '0' && i >= l + 1 && i <= r) {
                    cntZero--, cntOne++;
                }
                s[i] = '1';
            }
            ans++;
        }

    }
    // cout << s << "\n";
    cout << ans << "\n";
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