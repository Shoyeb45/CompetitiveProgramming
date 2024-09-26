#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
char ch;
string s;

vector<int> nxtGreenIndex(string s) {
    vector<int> a(s.size(), -1);

    stack<int> st;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'g') {
            while(!st.empty()) {
                a[st.top()] = i;
                st.pop();
            }
        }
        else {
            st.push(i);
        }
    }
    return a;
}
void solve() {
    cin >> n >> ch >> s;
    s.append(s);
    // cout << s << '\n';

    vector<int> nxtGreen = nxtGreenIndex(s);

    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ch) {
            if(nxtGreen[i] != -1) {
                ans = max(ans , nxtGreen[i] - i);
            }
        }
    }
    cout << ans << "\n";
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