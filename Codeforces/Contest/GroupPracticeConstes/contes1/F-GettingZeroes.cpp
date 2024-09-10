#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 32768;

int n;

// void solve() {
//     cin >> n;
//     queue<pair<ll, int>> q;
//     q.push({1LL * (n % mod), 0});
//     int ans = 20;
//     for(int i = 0; i <= 15; i++) {
//         for(int j = 0; j <= 15; j++) {
//             if( (ll)(1LL * (n + i) * pow(2, j) ) % mod == 0) {
//                 ans = min(ans, i + j);
//             }
//         }
//     }
//     cout << ans << ' ';
   
// }

void solve() {
    cin >> n;
    queue<pair<ll, int>> q;
    q.push({1LL * (n % mod), 0});
    bool visited[(int)(mod + 1)] = {false};
    while(true) {
        auto curr = q.front();
        q.pop();
        visited[curr.first] = true;
        // cout << curr.first << " ";
        if(curr.first == 0) {
            cout << curr.second << ' ';
            return;
        }

        if(!visited[(curr.first + 1) % mod]) {
            q.push({(curr.first + 1) % mod, curr.second + 1});
        }
        if(!visited[(curr.first * 2) % mod]) {
            q.push({(curr.first * 2) % mod, curr.second + 1});
        }
    }
   
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
