#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

char increment_char(char ch) {
    if (ch == 'z') {
        return 'a';
    }
    return (char) ch + 1;
}

string next_word(string s) {
    bool all_z = true;
    for (int i = s.size() - 1; i >= 0; i--) {
        char ch = s[i];
        s[i] = increment_char(s[i]);
        if (ch != 'z') {
            all_z = false;
            break;
        } 
    }
    if (all_z) {
        s.push_back('a');
    }
    return s;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    n = s.size();
    int freq[26];
    fill(freq, freq + 26, 0);
    for (char ch: s) {
        freq[ch - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) {
            cout << (char) (i + 'a') << "\n";
            return;
        }
    }

    set<string> l2;
    string temp = "";
    for (int i = 0; i < n; i++) {
        temp += s[i];
        if (temp.size() == 2) {
            l2.insert(temp);
            temp = "";
            temp += s[i];
        } 
    }    

    for (string start = "aa"; start.size() != 3; start = next_word(start)) {
        if (l2.find(start) == l2.end()) {
            cout << start << "\n";
            return;
        }
    }
   
    temp = s[1];
    l2.clear();
    for (int i = 1; i + 1 < n; i++) {
        l2.insert(s[i - 1] + temp + s[i + 1]);
        temp = s[i + 1];
    }    

    for (string st = "aaa"; ; st = next_word(st)) {
        if (l2.find(st) == l2.end()) {
            cout << st << "\n";
            return;
        }
    }
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