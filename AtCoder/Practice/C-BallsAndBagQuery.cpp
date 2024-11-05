#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int q;

int track[(int)1e6 + 1];

void solve() {
    cin >> q;
    memset(track, 0, sizeof(track));

    int ans = 0;
    while(q--) {
        int a;
        cin >> a;

        if(a == 1) {
            int x;
            cin >> x;
            track[x]++;

            if(track[x] == 1) {
                ans++;
            }
        }
        else if(a == 2) {
            int x;
            cin >> x;
            track[x]--;
            if(track[x] == 0) {
                ans--;
            }
        }
        else {
            cout << ans << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}