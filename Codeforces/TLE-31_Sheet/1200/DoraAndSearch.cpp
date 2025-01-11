#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x: a) {
        cin >> x;
    }

    set<int> mp;

    auto good = [&](int left, int right) {
        return !(a[left] == *mp.begin() || a[left] == *mp.rbegin() || a[right] == *mp.begin() || a[right] == *mp.rbegin());
    };
    for (int i = 1; i <= n; i++) {
        mp.insert(i);
    }

    for (int left = 0, right = n - 1; left <= right; ) {
        if (good(left, right)) {
            cout << left + 1 << " " << right + 1 << "\n";
            return;
        }   
        else {
            if (a[left] == *mp.begin() || a[left] == *mp.rbegin()) {
                mp.erase(a[left++]);
            }
            else if (a[right] == *mp.begin() || a[right] == *mp.rbegin()) {
                mp.erase(a[right--]);
            }
        }
    }
    cout << -1 << "\n";
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