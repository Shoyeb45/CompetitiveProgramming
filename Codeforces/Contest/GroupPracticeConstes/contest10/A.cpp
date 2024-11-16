#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;

void solve() {
    cin >> n >> m;

    vector<int> a(n + 1, 0);

    // Left = -1 , right = 1
    for (int i = 0; i < m; i++) {
        string s, t;
        int box;
        cin >> t >> t >> s >> t >> box;

        if (s == "right") {
            a[box] = 1;
        }
        else {
            a[box] = -1;
        }
    } 
    
    
    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            continue;
        }

        if (a[i] == 1) {
            // right
            int boxes = 0;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] == -1) { // found left
                    break;
                }
                else if (a[j] == 0) {
                    boxes++;
                }
            }
            ans = min (ans, boxes);
        }
        else {
            int boxes = 0;

            for (int j = i - 1; j >= 1; j--) {
                if (a[j] == 1) { // found right
                    break;
                }
                else if (a[j] == 0) {
                    boxes++;
                }
            }
            ans = min (ans, boxes);
        }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}