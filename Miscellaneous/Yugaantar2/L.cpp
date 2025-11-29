#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

string digit_to_str(int x) {
    switch (x) {
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    case 6:
        return "six";
    case 7:
        return "seven";
    case 8:
        return "eight";
    case 9:
        return "nine";
    }
    return "";
}

string tens_case(int n) {
    switch (n) {
    case 1:
        return "ten";
    case 2:
        return "twenty";
    case 3:
        return "thirty";
    case 4:
        return "forty";
    case 5:
        return "fifty";
    case 6:
        return "sixty";
    case 7:
        return "seventy";
    case 8:
        return "eighty";
    case 9:
        return "ninety";
    }
    return "";
}
string teens_case(int n) {
    switch (n) {
    case 11:
        return "eleven";
    case 12:
        return "twelve";
    case 13:
        return "thirteen";
    case 14:
        return "fourteen";
    case 15:
        return "fifteen";
    case 16:
        return "sixteen";
    case 17:
        return "seventeen";
    case 18:
        return "eighteen";
    case 19:
        return "nineteen";
    }
    return "";
}

string twos_case(string s, int n) {
    if (s.back() == '0') {
        return tens_case(s[0] - '0') + "\n";
    }
    if (n >= 11 && n <= 19) {
        return teens_case(n) +"\n";
    }
    return tens_case(s[0] - '0') + " " + digit_to_str(s.back() - '0') + "\n";
}

void solve() {
    int n;
    cin >> n;

    string s = to_string(n);

    int x = (int)log10(n) + 1;

    if (x == 1) {
        cout << digit_to_str(n) << "\n";
        return;
    }

    if (x == 2) {
        cout << twos_case(s, n);
        return;
    }

    if (x == 3) {
        if (n == 100) {
            cout << "hundred\n";
            return;
        }
        if (s[1] - '0' == 0 && s[2] - '0' == 0) {
            cout << digit_to_str(s[0] - '0') << " " << "hundred\n";
            return;
        }
        if (s[1] == '0') {
            cout << digit_to_str(s[0] - '0') << " hundred " << digit_to_str(s[2] - '0') << "\n";
            return;
        }
        
        cout << digit_to_str(s[0] - '0') << " hundred ";
        n = (s[1] - '0') * 10 + (s[2] - '0');
        s = to_string(n);
        cout << twos_case(s, n);
        return;
    }
    cout << "thousand\n";
}


int main() {
    NFS
#ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
    freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
    freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
#endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}