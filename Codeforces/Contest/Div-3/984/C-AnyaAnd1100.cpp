#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;   
int q;
int n;
int check(string s) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(i + 3 < n && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                ans++;
            }
        }
    }
    return ans;
}


void solve() {
    cin >> s >> q;
    n = s.size();
    bool isNoAll = false;
    if(s.size() < 4) {
        isNoAll = true;
    }

    int ans = check(s);
    // cout << ans << "\n";
    while(q--) {
        int idx;
        char c;
        cin >> idx >> c;
        if(isNoAll) {
            cout << "NO\n";
            continue;
        }
        idx--;

        for(int i = 0; i < 4; i++) {
            int t = i + idx;
            if(t < n && t - 3 >= 0) {
                if(s[t] == '0' && s[t - 1] == '0' && s[t - 2] == '1' && s[t - 3] == '1') {
                    ans -= 1;
                }
            }    
        }
        // debug("ans", ans);
        s[idx] = c;

        for(int i = 0; i < 4; i++) {
            int t = i + idx;
            if(t < n && t - 3 >= 0) {
                if(s[t] == '0' && s[t - 1] == '0' && s[t - 2] == '1' && s[t - 3] == '1') {
                    ans += 1;
                }
            }    
        }
        // debug("ans", ans);

        if(!ans) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
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