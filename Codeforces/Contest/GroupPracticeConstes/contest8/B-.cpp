#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

string s;
bool check(string s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> s;
    
    int n = s.size();
    for(char c = 'a'; c <= 'z'; c++) {
        string b = "";
        b += c, b += s;
        if(check(b)) {
            cout << b << "\n";
            return;
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {
        string b = "";
        b += s, b += c;
        if(check(b)) {
            cout << b << "\n";
            return;
        }
    }
    for(int i = 0; i < n; i++) {
        string temp = "";
        // debug("i", i);
        for(int j = 0; j <= i; j++) {
            temp += s[j];
        }
        string temp2 = "";
        for(int j = i + 1; j < n; j++) {
            temp2 += s[j];
        }
        // debug("temp", temp, "temp2", temp2);
        for(char ch = 'a'; ch <= 'z'; ch++) {
            // debug("ch", ch);
            string newS = "";
            newS += temp;
            newS += ch;
            newS += temp2;
            // cout << newS << "\n";
            if(check(newS)) {
                cout << newS << "\n";
                return;
            }
        }
    }

    cout << "NA\n";
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