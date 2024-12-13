#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
char newChar(char c) {
    if (c == 'z') {
        return 'a';
    }
    return (char)(c + 1);
}

char newChar(char c1, char c2) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch != c1 && ch != c2) {
            return ch;
        }
    }
    return ' ';
}
void solve() {
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            continue;
        }
        else {
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                s[i] = newChar(s[i + 1]);
            }
            else {
                if (i + 1 < s.size()) {
                    s[i] = newChar(s[i - 1], s[i + 1]);
                }
                else {
                    s[i] = newChar(s[i - 1]);
                }
            }
        }
    }
    cout << s << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}