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
const ll mod = 998244353;
int n;
vector<int> a, b;

ll dp[101][2];

ll f(int i, bool is_swapped) {
    if (i == n) {
        return 1;
    }

    if (dp[i][(int) is_swapped] != -1) {
        return dp[i][(int) is_swapped];
    }

    ll ans = 0;
    ll a_ele = is_swapped ? b[i - 1]: a[i - 1];
    ll b_ele = is_swapped ? a[i - 1]: b[i - 1];

    if (a_ele <= a[i] && b_ele <= b[i]) {
        ans = (ans + f(i + 1, 0)) % mod;        
    }

    if (a_ele <= b[i] && b_ele <= a[i]) {
        ans = (ans + f(i + 1, 1)) % mod;        
    }

    return dp[i][(int) is_swapped] = ans;
}

void solve() {
    cin >> n;
    memset(dp, -1, sizeof dp);

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }    
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }    
    cout << (f(1, 0) + f(1, 1)) % mod << "\n";
    a.clear(), b.clear();
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