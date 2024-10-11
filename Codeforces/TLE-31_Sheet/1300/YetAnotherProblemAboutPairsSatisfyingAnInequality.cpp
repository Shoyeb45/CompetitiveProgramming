#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;

int lowerBound(vector<pair<int, int>> &vp, int target) {
    int low = 0, high = vp.size() - 1;
    int ans = vp.size();
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(vp[mid].first > target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
void solve() {
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x < i) {
            vp.push_back({x, i});
        }
    }
    sort(range(vp));
    ll ans = 0;
    for(auto it: vp) {
        int idx = lowerBound(vp, it.second);
        ans += 1LL * (vp.size() - idx);
        // cout << idx << " " << it.first << "\n";
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