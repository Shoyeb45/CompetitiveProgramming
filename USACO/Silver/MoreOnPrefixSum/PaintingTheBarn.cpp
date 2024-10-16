#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
#define MAX 1005

int n, k;
void solve() {
    cin >> n >> k;
    vector<vector<int>> a1(MAX, vector<int>(MAX, 0));

    while(n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a1[x1][y1]++;
        a1[x2][y1]--;
        a1[x2][y2]++;
        a1[x1][y2]--;
    }

    for(int i = 1; i <= 1000; i++) {
        a1[0][i] += a1[0][i - 1];
    }
    for(int i = 1; i <= 1000; i++) {
        a1[i][0] += a1[i - 1][0];
    }

    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            a1[i][j] += (a1[i - 1][j] + a1[i][j - 1]) - a1[i - 1][j - 1];
        }
    }
 

    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(a1[i][j] == k) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() { 
    NFS
    #ifndef ONLINE_JUDGE
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}