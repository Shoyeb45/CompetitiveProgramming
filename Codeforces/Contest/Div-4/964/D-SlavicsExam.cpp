#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


bool isSubseq(string o, string s) {
    int i = 0, j = 0;

    while(i < o.size() && j < s.size()) {
        if(s[j] == o[i]) {
            j++;
        }
        i++;
    }
    return j == s.size();
}

void solve() {
    string s, t;
    cin >> s >> t;

    int num = 0;
    loop(i, s.size()) {
        num += (s[i] == '?');
    }

    if(isSubseq(s, t)) {
        loop(i, s.size()) {
            if(s[i] == '?') {
                s[i] = 'a';
            }
        }
        cout << "YES\n" << s << '\n';
        return;
    }
    // if(t.size() > s.size() || (num < ))

    int i = 0, j = 0;

    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) {
            j++;
        } else {
            if(s[i] == '?') {
                s[i] = t[j];
                j++;
            }
        }
        i++;
    }

    if(isSubseq(s, t)) {
        loop(i, s.size()) {
            if(s[i] == '?') {
                s[i] = 'z';
            }
        }
        cout << "YES\n" << s << '\n';
        return;
    } else {
        cout << "NO\n";
    }
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
