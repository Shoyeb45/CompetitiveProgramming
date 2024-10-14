#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve(int kadanes) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll ans = INT_MIN, currSum = 0;
    for(auto x: a) {
        if(currSum < 0) {
            currSum = 0;
        }
        currSum += x;
        ans = max(ans, currSum);
    }

    cout << ans << "\n";
}

void solve(string prefix) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }

    vector<ll> pref(n + 1);
    for(int i = 1; i < n + 1; i++) {
        pref[i] += pref[i - 1] + a[i - 1];
    }

    ll ans = INT_MIN, minPref = pref[0];
    for(int i = 1; i <= n; i++) {
        ans = max(ans, 1LL * (pref[i] - minPref));
        minPref = min(minPref, pref[i]);
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
    // cin >> tt;

    while (tt--) {
        solve("prefixApproach");
    }


    return 0;
}