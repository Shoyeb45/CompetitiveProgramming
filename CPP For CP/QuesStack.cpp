#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
     for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.top() == '(' && s[i] == ')')   st.pop();
                else if(st.top() == '[' && s[i] == ']') st.pop();
                else if(st.top() == '{' && s[i] == '}') st.pop();
            }
        }
        
    cout << st.empty();    
    return 0;
}