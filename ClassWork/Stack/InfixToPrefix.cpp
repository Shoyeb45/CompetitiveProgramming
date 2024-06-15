#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
void modify(string &s) {
    reverse(s.begin(), s.end());
    loop(i, s.size()) {
        if(s[i] == '(') {
            s[i] = ')';
        } else if(s[i] == ')'){
            s[i] = '(';
        }
    }
}

int priority(char c) {
    if(c == '+' || c == '-')
        return 1;
    else if(c == '/' || c == '*')
        return 2;
    return -1;
}

void solve() {
    string s;
    cin >> s;
    modify(s);

    string ans = "";
    stack<char> st;
    loop(i, s.size()) {
        if(isdigit(s[i])) {
            ans += s[i];
        } else if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && priority(st.top()) > priority(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
