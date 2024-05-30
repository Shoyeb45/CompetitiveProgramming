#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool isSorted(string s) {
    string new_s = s;
    sort(new_s.begin(), new_s.end());
    return (new_s == s);
}

bool allDigits(string s) {
    loop(i, s.size()) {
        if(!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

bool allLowerCase(string s) {
    loop(i, s.size()) {
        if(!islower(s[i])) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s, s1 = "", s2 = "";
    cin >> s;
    
    int ind = 0;
    loop(i, n) {
        if(islower(s[i])) {
            ind = i;
            break;
        }
    }
    for(int i = 0; i < ind; i++) {
        s1 += s[i];
    }
    for(int i = ind; i < n; i++) {
        s2 += s[i];
    }

    bool check1 = isSorted(s1), check2 = isSorted(s2);
    if((s1 == "" && check2) || (s2 == "" && check1)) {
        cout << "YES\n";
        return;
    }

    if(allDigits(s1) && allLowerCase(s2) && check1 && check2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return;
}

void solve2() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(is_sorted(s.begin(), s.end()))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
