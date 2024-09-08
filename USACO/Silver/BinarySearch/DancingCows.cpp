#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, t;
vector<int> d;

bool check(int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int last = 0;
    for(int i = 0; i < n; i++) {
        if(pq.size() == k) {
            last = pq.top();
            pq.pop();
        }

        if(last + d[i] > t) {
            return 0;
        }
        pq.push(last + d[i]);
    }
    return 1;
}
void solve() {
    cin >> n >> t;
    d.resize(n);
    for(auto &x: d) {
        cin >> x;
    }

    int ans = -1;
    int low = 1, high = n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
