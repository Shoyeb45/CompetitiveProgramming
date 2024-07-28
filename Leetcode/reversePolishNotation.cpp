#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void display(stack<int> st) {
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << '\n';
    }

    int toDigit(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) {
            return tokens[0][0] - '0';
        }
        stack<int> st;
        
        for(int i = 0 ; i < tokens.size(); i++) {
            if(tokens[i][0] >= '0' && tokens[i][0] <= '9') {
                st.push(toDigit(tokens[i]));
            } else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                int res = 0;
                char oper = tokens[i][0];

                if(oper == '+') {
                    res = x + y;
                } 
                else if(oper == '-') {
                    res = y - x;
                } 
                else if(oper == '*') {
                    res = y * x;
                } 
                else {
                    res = y / x;
                }
                st.push(res);
            }
            display(st);
        }

        return st.top();
    }
};
int main() {
    Solution sn;

    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = sn.evalRPN(s);
    cout << ans << '\n';
}