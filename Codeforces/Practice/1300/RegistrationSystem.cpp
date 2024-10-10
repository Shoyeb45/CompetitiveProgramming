#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;

string numToStr(int num) {
    string ans = "";
    while(num > 0) {
        ans += (num % 10) + '0';
        num /= 10;
    }
    reverse(range(ans));
    return ans;
}
void solve() {
    cin >> n;
    map<string, int> mp;
    while(n--) {
        string s;
        cin >> s;

        if(mp.find(s) != mp.end()) {
            string newS = s;
            newS += numToStr(mp[s]);
            mp[s]++;
            cout << newS << "\n";
        }
        else {
            cout << "OK\n";
            mp[s]++;
            
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
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}