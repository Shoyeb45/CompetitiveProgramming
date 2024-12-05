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
    cin >> n >> s;
    map<char, int> mp;
    for (auto c : s) {
        mp[c]++;
    }
    
    char mx = s[0];
    int mxY = 0;
    for (auto it : mp) {
        if (it.second > mxY) {
            mxY = it.second;
            mx = it.first;
        }
    }   
    char mn = s[0];
    int mnY = INT_MAX;  
    for (auto it : mp) {
        if (it.second <= mnY) {
            mnY = it.second;
            mn = it.first;
        }
    }   

    for (int i = 0; i < n; i++) {
        if (s[i] == mn) {
            s[i] = mx;
            break;
        }
    }
    cout << s << "\n";
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