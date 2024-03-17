#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n; 
        cin >> n;
        string s;
        cin >> s;
        int cnt1 = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#') cnt1++;
        }

        if(cnt1 == s.size())  cout << 0 <<'\n';
        else if (cnt1 == 0 && s.size() >= 3)   cout << 2 << '\n';
        else {
            bool val = false;
            for(int i = 0 ; i <= n - 3; i++) {
                if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.')   {
                    val = true;
                    break;
                }
            }

            if(val) cout << 2 << '\n';
            else {
                int cnt2 = 0;
                for(int i = 0; i < s.size(); i++) {
                    if(s[i] == '.') cnt2++;
                }

                cout << cnt2 <<'\n';
            }
        }
    }
    
}