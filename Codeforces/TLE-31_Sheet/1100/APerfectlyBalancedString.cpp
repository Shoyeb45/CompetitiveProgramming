#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
void solve() {
    cin >> s;
    
    set<char> st;
    int k;
    for (k = 0; k < s.size(); k++) {
        if (st.find(s[k]) == st.end()) {
            st.insert(s[k]);
        } else {
            break;
        }
    }

    for (int i = k; i < s.size(); i++) {
        if (s[i] != s[i - k]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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