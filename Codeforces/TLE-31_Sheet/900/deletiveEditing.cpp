#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


map<char,int> occurence(string s) {
    map<char, int> m;
    for(char & ch : s)  m[ch]++;

    return m;
}

void solve() {
    string s, t;
    cin >> s >> t;
    
    if(s == t) {
        cout << "YES\n";
        return;
    } else {
        map<char, int> map_s = occurence(s);
        map<char, int> map_t = occurence(t);

        for(char & a: t) {
            if(map_s[a] - map_t[a] < 0) {
                cout << "NO\n";
                return;
            }
        }

        for(char & a: t) {
            for(int i = 0, j = 1; j <= map_s[a] - map_t[a] && i < s.size(); i++) {
                if(s[i] == a) {
                    s.erase(i, 1);
                    j++;
                }
            }
        }
        map<char, int> map_sm = occurence(s);
        for(char & a: t) {
            if(map_sm[a] - map_t[a] < 0) {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
    }
    
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
}
