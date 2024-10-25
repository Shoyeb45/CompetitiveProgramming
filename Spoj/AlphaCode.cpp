#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll dp[5001] = {0};

string combine(char c, char b) {
    string s = "";
    s += c;
    s += b;
    return s;
}
ll f(int i, string s) {
    if(i >= s.size()) {
        return 1;
    }    
    
    if(s[i] == '0') {
        return dp[i] = 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }

    ll ans1 = 0;
    if( i < s.size() - 1 && stoi(combine(s[i], s[i + 1])) >= 10 && stoi(combine(s[i], s[i + 1])) <= 26) {
        ans1 = f(i + 2, s);
    }

    ll ans2 = 0;    
    if(s[i] != '0') {
        ans2 = f(i + 1, s);
    }
  

    return dp[i] = ans1 + ans2;
}

void solve(string s) {
    memset(dp, -1, sizeof(dp));
    cout << f(0, s) << "\n";
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

    string s;
    while (true) {
        cin >> s;
        if(s == "0") {
            break;
        }
        solve(s);
    }

    return 0;
}