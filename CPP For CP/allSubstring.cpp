#include<bits/stdc++.h>
using namespace std;

void printSubstring(string s, int pos) {
    for(int i = 1; i <= s.size() - pos; i++) {
        cout << s.substr(pos, i) << endl;
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