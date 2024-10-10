#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, c;

void solve() {
    cin >> n >> c; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push(x + i);
    }


    int ans = 0;
    while(!pq.empty()) {
        int t = pq.top();
        pq.pop();
        if(c <= 0) {
            break;
        }

        if(t <= c) {
            c -= t;
            c = max(c, 0);
            ans++;
        } 
    }
    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}