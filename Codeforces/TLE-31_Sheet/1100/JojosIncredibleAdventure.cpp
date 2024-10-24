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
    s += s;

    int mx = 0;
    for(int i = 0; i < s.size(); ) {
        if(s[i] == '1') {
            int temp = 0;
            while(i < s.size() && s[i] == '1') {
                i++, temp++;
            }
            mx = max(temp, mx);
        }
        else {
            i++;
        }
    }

    if(mx > s.size() / 2) {
        cout << 1LL * s.size() * s.size() / 4 << "\n";
    }
    else {
        ll a = (mx + 1) / 2;
        ll b = (mx + 2) / 2;
        cout << 1LL * a * b << "\n";
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