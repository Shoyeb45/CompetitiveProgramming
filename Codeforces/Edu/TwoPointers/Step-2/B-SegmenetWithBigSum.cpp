#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll s;
void solve() {
    cin >> n >> s;
    vector<ll> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    int right = 0, ans = INT_MAX, left = 0;
    ll currSum = 0;
    for(int right = 0; right < n; right++) {
        currSum += a[right];
        while(left < n && currSum >= s) {
            ans = min(ans, right - left + 1);
            currSum -= a[left++];
        }
    }
    if(ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << '\n';
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}