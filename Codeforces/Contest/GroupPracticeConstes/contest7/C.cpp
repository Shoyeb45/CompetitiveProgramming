#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll n;
void solve() {
    cin >> n;
    string s = to_string(n);
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        ans += s[0];
    }
    ll temp = stoll(ans);
    if(temp >= n) {
        cout << temp << "\n";
    }
    else {
        if(ans[0] == '9') {
            for(int i = 0; i < s.size() + 1; i++) {
                cout << ans[0];
            }
            cout << "\n";
        }
        else {
            for(int i = 0; i < ans.size(); i++) {
                cout << (char)(ans[i] + 1);
            }
            cout << "\n";
        }
    }
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;

    while (tt--) {
        solve();
    }


    return 0;
}