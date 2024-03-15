#include<bits/stdc++.h>
using namespace std;

int main(){
    string seq;
    cin >> seq;
    stack<char> st;
    for (int i = 0 ; i < seq.size(); i++) {
        // opening bracket
        if(seq[i] == '{' || seq[i] == '[' || seq[i] == '(' ) {
            st.push(seq[i]);
        } else {
            if(st.top() == '}')
        }
    }
    return 0;
}