#include <bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
using ld = long double;

ll a, b, v1, v2;
int n;

void solve(int secondWay) {
    cin >> a >> b >> v1 >> v2 >> n;
    
    vector<pair<int, int>> points;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    ll c1 = v1 * v2;
    ll k = 1LL * a * b;
    ld eps = 1e-25;

    vector<pair<ld, int>> ans (n, {1e25, -1});

    for (int i = 0; i < n; i++) {
        int x = points[i].first, y = points[i].second;

        ll c2 = (1LL * x * v2) - (1LL * a * v2) + (1LL * v1 * b) - (1LL * y * v2);
        ll c3 = (1LL * y * a) + (1LL * x * b) - k;
        ll D = (1LL * c2 * c2) - (4LL * c1 * c3);

        if (D < -eps) {
            continue;
        }

        ld t1 = ((ld)c2 - sqrt(D)) / ((ld)(2 * c1)); 
        ld t2 = ((ld)c2 + sqrt(D)) / ((ld)(2 * c1)); 

        if (t1 >= 0) {
            ans[i] = {t1, x};
        }
        else if (t2 >= 0) {
            ans[i] = {t2, x};
        }
    }

    
    auto it = min_element(range(ans));

    if (it -> second == -1) {
        cout << -1 << "\n";
    } else {
        cout << (it - ans.begin()) + 1 << "\n";
    }
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
        solve(3);
    }

    return 0;
}
