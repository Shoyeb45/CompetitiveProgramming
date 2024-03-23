#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.begin(), s.end());

            int i = 0, odd = 0;
            while (i < s.size()) {
                int cnt = 1;
                int j = i + 1;
                while (j < s.size() && s[i] == s[j]) {
                    cnt++;
                    j++;
                }
                
                odd += (cnt % 2 != 0);
                i = j;
            }

        if(k < odd - 1) cout << "NO\n";
        else    cout << "YES\n";
            
    }
    
}