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

string add_time(string &s, int hr, int mn) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    int temp = minute + mn >= 60;
    hour = (hour + hr + temp) % 24;
    minute = (minute + mn) % 60;
    string ans = "";
    if (hour < 10) {
        ans += "0";
    }
    ans += to_string(hour) + ":";
    if (minute < 10) {
        ans += "0";
    }
    return ans + to_string(minute);
}

bool is_palindrome(string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    int x;
    cin >> s >> x;

    int hr = x / 60, minutes = x - hr * 60;
    string temp = s;
    int ans = 0;
    do {
        temp = add_time(temp, hr, minutes);
        ans += is_palindrome(temp);
    } while (temp != s);

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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}