#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), missing;
    vector<int> temp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        temp[a[i]]++;
    }   
    for (int i = 1; i <= n; i++) {
        if (temp[i] == 0) {
            missing.push_back(i);
        }
    }
    reverse(range(missing));
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = missing[idx++];
        }
    }
 

    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 0; i--) {
        if (a[i] != i) {
            r = i;
            break;
        }
    }
    if (r == l) {
        cout << 0 << "\n";
        return;
    }
    cout << r - l + 1 << "\n";
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