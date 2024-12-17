#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    int l = 0, r = n - 1;

    for (; l < n; l++) {
        if (s[l] == '*') {
            break;
        }
    }
    
    for (; r >= 0; r--) {
        if (s[r] == '*') {
            break;
        }
    }

    if ((l >= n && r < 0) || (l == r)) {
        cout << 0 << "\n";
        return;
    }

    deque<int> dq;

    for (int i = l; i <= r; i++) {
        if (s[i] == '.') {
            dq.push_back(i);
        }
    }

    ll ans = 0;
    while (!dq.empty()) {
        int idx1 = dq.front(), idx2 = dq.back();

        if (idx1 >= r || idx2 <= l) {
            break;
        }

        if (idx1  - l >= r - idx2) {
            s[idx2] = '*';
            ans += (r - idx2);
            dq.pop_back();
            r--;
        }
        else {
            s[idx1] =  '*';
            ans += (idx1 - l);
            dq.pop_front();
            l++;
        }
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