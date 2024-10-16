#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<string> a, b;
int mismatchChars(string s1, string s2) {
    if(s1 == s2) {
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < s1.size(); i++) {
        ans += (s1[i] != s2[i]);
    }

    return ans;
}

void solve() {
    cin >> n;
    a.resize(n), b.resize(n);

    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }

    int ans = 0;
    for(auto x: b) {
        int temp = INT_MAX;
        for(auto y: a) {
            if(y.size() == x.size()) {
                temp = min(temp, mismatchChars(x, y));
            } 
        }
        ans += temp;
    }

    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}