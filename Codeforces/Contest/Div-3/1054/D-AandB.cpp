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
    string s;
    cin >> n >> s;
    vector<ll> pos_a, pos_b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            pos_a.push_back(i);
        } else {
            pos_b.push_back(i);
        }
    }   
    if (pos_a.empty() || pos_b.empty()) {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < pos_a.size(); i++) {
        pos_a[i] = pos_a[i] - i;
    }
    for (int i = 0; i < pos_b.size(); i++) {
        pos_b[i] = pos_b[i] - i;
    }
    sort(range(pos_a));
    sort(range(pos_b));

    ll ans = 0;
    int x = pos_a[pos_a.size() / 2]; 
    // try to group a's together.
    for (int i = 0; i < pos_a.size(); i++) {
        ans += abs(pos_a[i] - x);
    }
    x = pos_b[pos_b.size() / 2];
    
    ll temp_ans = 0;
    // group b's together
    for (int i = 0; i < pos_b.size(); i++) {
        temp_ans += abs(pos_b[i] - x);
    }
    cout << min(ans, temp_ans) << "\n";
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