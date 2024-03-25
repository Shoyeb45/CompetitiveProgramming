#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string x, string s) {
    int j = 0;
    bool ans = true;
    for(int i = 0 ; i < x.size(); i++) {
        ans = true;
        while(j < s.size()) {
            if(s[i] == x[i]) {
                ans = true;
            } else {
                ans = false;
                break;
            }
            j++;
        }

        j = 0;
        if(ans) break;
    }
    return ans;
}

int main () {
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x; 
        cin >> s;    
        cout << isSubstring(x, s);
    }
}