#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int k;
void solve() {
    cin >> k;
    int num = k - 2;
    
    map<int, int> mp;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        mp[x]++;
    }

    for (ll i = 1; 1LL * i * i <= num; i++) {
        if (num % i == 0) {
            if (num / i == i) {
                if (mp.find(i) != mp.end()) {
                    if (mp[i] >= 2) {
                        cout << i << " " << i << "\n";
                        return;
                    }
                }
            }
            else {
                ll temp1 = i, temp2 = num / i;
                if (mp.find(temp1) != mp.end() && mp.find(temp2) != mp.end()) {
                    cout << temp1 << " " << temp2 << "\n";
                    return;
                }
            }
        }
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
        solve();
    }

    return 0;
}