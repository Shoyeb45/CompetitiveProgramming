#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll x, y;
vector<ll> a;

int lb(vector<ll> &a, int low, ll val) {
    int high = a.size() - 1;
    int ans = a.size();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] >= val) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int ub(vector<ll> &a, int low, ll val) {
    int high = a.size() - 1;
    int ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] <= val) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> x >> y;
    ll sum = 0;
    a.resize(n);

    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    sort(range(a));


    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int idx_up = ub(a, i + 1, sum - x - a[i]), idx_lb = lb(a, i + 1, sum - y - a[i]);

        if (idx_up >= idx_lb)
        ans += idx_up - idx_lb + 1;
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