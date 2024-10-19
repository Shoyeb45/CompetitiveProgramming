#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s, t, p;
void solve() {
    cin >> s >> t >> p;
    map<char, int> mp;

    for(char x: p) {
        mp[x]++;
    }

    if(s.size() == t.size() && s != t) {
        cout << "NO\n";
        return;
    }

    if(s.size() > t.size()) {
        cout << "NO\n";
        return;
    }


    int j = 0;
    for(int i = 0; i < t.size(); i++) {
        if(j < s.size() && s[j] == t[i]) {
             j++;
        }
        else {
            if(mp[t[i]]>0) {
                mp[t[i]]--;
            } 
            else {
                cout << "NO\n";
                return;
            }
        }
    } 
    if(j == s.size()) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}