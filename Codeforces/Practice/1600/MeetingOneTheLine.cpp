#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
using ld = long double;

int n;
vector<ll> x, t;

bool check(ld mid, ld &ans) {
    ld leftMax = -1e13, rightMin = 1e13;

    for (int i = 0; i < n; i++) {
        if (t[i] > mid) {
            return false;
        }
        ld left = x[i] - (mid - t[i]), right = x[i] + (mid - t[i]);
        leftMax = max (left, leftMax);
        rightMin = min (right, rightMin);
        ans = max (ans, leftMax);
    }

    return rightMin - leftMax >= 0;
}

void solve() {
    cin >> n;
    x.resize(n), t.resize(n);

    for (auto &y : x) {
        cin >> y;
    } 
    for (auto &y : t) {
        cin >> y;
    }

    ld low = *max_element(range(t)), high = 1e10;
    ld ans = -1;
    int iter = 200;

    while (iter--) {
        ld mid = low + (high - low) / 2;
        ld temp = 0;
        if (check(mid, temp)) {
            ans = temp;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

  
    cout << fixed << setprecision(8) << ans <<  "\n";
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