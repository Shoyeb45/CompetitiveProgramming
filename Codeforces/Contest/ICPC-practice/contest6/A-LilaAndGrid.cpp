#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<string> a;
ll power(ll k, ll x) {
    if(x == 1) {
        return k % mod;
    }
    if(x == 0) {
        return 1;
    }

    ll temp = power(k, x / 2) % mod;
    if(x % 2 == 0) {
        return (1LL * temp * temp) % mod;
    } else {
        return (1LL * temp * temp % mod * k) % mod;
    }
}


void solve() {
    cin >> n >> m;
    for(int i  = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    // vector<vector<bool>> vis(n, vector<bool> (m, 0));
    // ll compo = 0;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(!vis[i][j]) {
    //             compo++;
    //             queue<pair<int, int>> q;
    //             q.push({i, j});
    //             vis[i][j] = 1;
 
    //             while(!q.empty()) {
    //                 auto curr = q.front();
    //                 q.pop();
 
    //                 for(int k = 0; k < 4; k++) {
    //                     int nx = dx[k] + curr.first, ny = dy[k] + curr.second;
    //                     if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && a[nx][ny] == a[curr.first][curr.second]) {
    //                         vis[nx][ny] = 1;
    //                         q.push({nx, ny});
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    ll b = 0, w = 0;
    ll num = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch = a[i][j];

            int adj = 0, temp = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k] , ny = j + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    adj++;
                    if(a[nx][ny] == ch) {
                        temp++;
                    }
                }
            }

            if(temp == adj) {
                if(ch == 'B') {
                    b++;
                }
                else {
                    w++;
                }
                num++;
            }
        }
    }

    ll ans = power(2, num) % mod;
    
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