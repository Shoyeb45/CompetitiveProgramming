
#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;

        if(s[0] == s[s.size() - 1])    cout << s << "\n";
        else {
            s[s.size() - 1] = s[0];
            cout << s << '\n';
        }
    }
}
