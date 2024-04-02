#include<bits/stdc++.h>
using namespace std;

void printSubstring(string s, int pos) {
    for(int i = 1; i <= s.size() - pos; i++) {
        cout << s.substr(pos, i) << endl;
    }
}

void printSubseq(string s, int pos) {
    if(pos <= s.size() - 2) {
        for(int i = pos + 2; i < s.size(); i++) {
            cout << s[pos] << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0 ; i < n ; i++) {
        printSubstring(s, i);
    }
    cout << endl;
}