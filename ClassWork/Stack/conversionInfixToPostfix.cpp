#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int priority(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '/' || op == '*')
        return 2;
    if(op == '^')
        return 3;

    return -1;
}

string infix_to_postfix(string s) {
    string ans = "";
    stack<char> st;

    for(auto c: s) {
        if(c == '(') {
            st.push(c);
        } else if(isdigit(c)) {
            ans += c;
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && (priority(st.top()) >= priority(c))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    getline(cin , s);

    string new_s = "";
        for(char c: s) {
            if(c != ' ') {
                new_s += c;
            }
        }
    cout << infix_to_postfix(new_s) << '\n';
    
    return 0;
}
