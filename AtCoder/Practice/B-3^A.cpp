#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int m;
int log3(int x) {
    int ans = 0;
    while(x > 0) {
        ans++;
        x /= 3;
    }
    return ans;
}
void solve() {
    cin >> m;
    vector<int> ans;
    int power = 0;
    while(m > 0) {
        int di = m % 3;
        m /= 3;

        if(di == 2) {
            ans.push_back(power), ans.push_back(power);
        }
        else if(di == 1) {
            ans.push_back(power);
        }
        power++;
    }
    cout << ans.size() << "\n";
    for(auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}