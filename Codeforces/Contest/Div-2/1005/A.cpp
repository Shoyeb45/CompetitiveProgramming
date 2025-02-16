#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
string s;
void solve() {
    cin >> n >> s;

    int cnt1 = 0, cnt0 = 0;

    for (int i = 0; i < n;) {
        if (s[i] == '1') {
            while (i < n && s[i] == '1') {
                i++;
            }
            cnt1++;
        }
        else {
            while (i < n && s[i] == '0') {
                i++;
            }
            cnt0++;
        }
    }

    if (s[0] == '0') {
        cout << cnt1 + cnt0 - 1 << "\n";
    }
    else {
        cout << cnt1 + cnt0 << "\n";
    }
    // debug("c1", cnt1, "c0" , cnt0);

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