#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ostream& operator<<(ostream& os, map<int, int> &mp) {
    for (auto it : mp) {
        cout << it.first << " ";
    }
    cout << "\n";
    return os;
}

int n, w;
void solve() {
    cin >> n >> w;
    map<int, int> ms;

    for(int i = 0, x; i < n; i++) {
        cin >> x;
        ms[x]++;
    }

    int ans = 0;
    while (!ms.empty()) {
        int temp = w;

        while (temp > 0) {
            if (temp >= ms.rbegin() -> first) {
                temp -= ms.rbegin() -> first;
                ms[ms.rbegin() -> first]--;

                if (ms.rbegin() -> second == 0) {
                    ms.erase(ms.rbegin() -> first);
                }
            }
            else {
                break;
            }
            if (ms.empty()) {
                break;
            }
        }


        ans++;
    }

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