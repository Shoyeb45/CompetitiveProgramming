#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;



int n;
vector<int> p;
string s;

int f(vector<int> &p, vector<int> &dp, int ind, int prev,unordered_map<int, int> &mp) {
    if(mp.find(ind) != mp.end()) {
        return 0;
    }

    if(dp[ind] != -1) {
        return dp[ind];
    }

    mp[ind] = 0;
    int cnt = (s[prev] == '0'? 1: 0) + f(p, dp, p[ind], ind, mp);
    return dp[ind] = cnt;
}

void solve() {
    cin >> n;
    p.resize(n);
    for(auto &x: p) {
        cin >> x;
        x--;
    }

    cin >> s; 

    vector<int> ans(n);
    vector<int> visited(n, -1);

    for(int i = 0; i < n; i++) {
        unordered_map<int, int> mp;
        int strt = p[i];
        int tempAns = 0;

        // mp[strt] = 0;
        // while(mp.find(p[strt]) == mp.end()) {
        //     mp[strt] = 0;
        //     if(s[strt] == '0') {
        //         tempAns++;
        //     }
        //     strt = p[strt];
        // }

        // if(s[strt] == '0') {
        //     tempAns++;
        // }
        // ans[i] = tempAns;
        
    }

    for(auto x: ans) {
        cout << x << ' ';
    }
    cout << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
