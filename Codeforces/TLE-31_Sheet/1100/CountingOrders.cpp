#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<int> a, b;
int n;
void solve() {
    cin >> n;
    a.resize(n), b.resize(n);

    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    auto ub  =[&](int num) {
        int ans = -1, low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] <= num) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    };
    ll ans = 1;


    for (int i = 0; i < n; i++) {
        int num = n - ub(b[i]) - 1;
        ans = (1LL * ans * max((num - i), 0)) % mod;
    }
    cout << ans << "\n";
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