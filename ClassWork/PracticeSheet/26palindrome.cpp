#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    string s;
    cin >> s;

    bool check = false;
    for(int i = 0; i < s.size()/2; i++) {
        if(s[i] == s[s.size() - i - 1]) check = true;
        else {
            check = false;
            break;
        }
    }

    if(check)   cout << "YES\n";
    else    cout << "NO\n";
   
}
