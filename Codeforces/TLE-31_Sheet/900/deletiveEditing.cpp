#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s, t;
void solve() {
    cin >> s >> t;

    int j = s.size() - 1;
    vector<bool> is_taken(s.size(), false);

    for (int i = t.size() - 1; i >= 0; i--) {
        for (; j >= 0; j--) {
            if (t[i] == s[j]) {
                for (int k = j + 1; k < s.size(); k++) {
                    if (s[k] == t[i] && !is_taken[k]) {
                        cout << "NO\n";
                        return;
                    }
                }
                is_taken[j--] = true;
                break;
            }
        }

        
        // t[i] == s[j]
        
    }

    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (is_taken[i]) {
            ans += s[i]; 
        }
    }
    if (ans == t) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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