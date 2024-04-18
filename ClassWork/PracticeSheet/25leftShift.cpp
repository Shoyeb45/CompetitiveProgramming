#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

// Concatenating string with string will give all versions of rotation of that string
string rotate(string s, int k) {
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.end());

    return s;
}
int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;
    
    string leftShift;

    for(int i = k % s.size(); i < s.size(); i++) {
        leftShift += s[i];
    }
    for(int i = 0; i < k; i++) {
        leftShift += s[i];
    }
    cout << leftShift << "\n";
    cout << rotate(s, k) << "\n";
}
