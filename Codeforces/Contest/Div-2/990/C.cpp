#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<pair<int, int>> a;
void solve() {
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    ll mxVal = a[0].first + a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].first + a[i].second > mxVal) {
            mxVal = a[i].first + a[i].second;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i].first + a[i].second == mxVal) {
            a.erase(a.begin() + i);
        }
    }

    sort(a.begin(), a.end(), [&](const pair<int, int> p1, const pair<int, int> p2) {
        return p1.second >= p2.second;
    });

    ll rowOne = 0;
    for (auto x : a) {
        rowOne += x.first;
    }

    ll curTwo = 0;
    int j = 0;
    ll ans = mxVal + rowOne;

    for (int i = 1; i <= n - 1; i++) {
        rowOne -= a[j].first, curTwo += a[j++].second;
        // debug("one", rowOne, "two", curTwo);
        ll temp = (mxVal + rowOne + curTwo); 
        ans = max(ans, temp);
    }
    cout <<ans << "\n";
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