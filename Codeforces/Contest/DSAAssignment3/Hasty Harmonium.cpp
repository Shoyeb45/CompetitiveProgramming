#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

string s;

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
    cin >> s;
    
    string ans = "";
    loop(i, 26) {
    char a = 'a' + i;
        loop(j, 26) {
            char b = 'a' + j;
            string temp = "";
            temp += a;
            temp += b;
            if(isSubseq(s, temp)) {
                cout << temp;
                return;
            }
        }
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
