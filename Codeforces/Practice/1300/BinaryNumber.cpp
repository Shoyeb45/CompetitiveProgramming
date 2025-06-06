#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
void solve() {
    cin >> s;
    int n = (int)s.size();
    reverse(range(s));
    // Not needed
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }

    ll one = 0, ans = 0;
    for(int i = 0; i < n; ) {

        if(s[i] == '0') {
            while(i < n && s[i] == '0') {
                ans++, i++; // Count all the zeroes
            }
            one = 0;
        }
        else {
            one = 0;
            while(i < n && s[i] == '1') {
                one++, i++; // Count numberOfOne
            }
            s[i] = '1'; // Set ith 0 to 1

            if(i >= n && one > 1 || i < n) { // Extra codition for discussed case
                ans += one + 1; 
            }
        }
    }
    // Output the answer
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}