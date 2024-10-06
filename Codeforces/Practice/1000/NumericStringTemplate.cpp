#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
string s;
vector<int> a;
bool isAllEqual(vector<int> &idx) {
    for(int i = 0; i < idx.size() - 1; i++) {
        if(a[idx[i]] != a[idx[i + 1]]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    a.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    while(m--) {
        cin >> s;

        if(s.size() != n) {
            cout << "NO\n";
        }
        else {
            unordered_map<int, char> mp1;
            unordered_map<char, int> mp2;
            bool chk = true;

            for(int i = 0; i < n; i++) {
                if(mp1.find(a[i]) == mp1.end() && mp2.find(s[i]) == mp2.end()) {
                    mp1[a[i]] = s[i];
                    mp2[s[i]] = a[i];
                }
                else if((mp1.find(a[i]) != mp1.end() && mp1[a[i]] != s[i]) || (mp2.find(s[i]) != mp2.end() && mp2[s[i]] != a[i]) ) {
                    chk = false;
                    break;
                }
            }
            

           

            cout << (chk ? "YES\n" : "NO\n");
        }
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