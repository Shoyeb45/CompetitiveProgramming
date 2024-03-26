#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string s1, string s2) {
    size_t found = s1.find(s2);
    return (found != string::npos);
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
        if(isSubstring(x, s))   cout << 0 << "\n";
        else {
            for(int i = 1 ; ; i++) {
                x = x + x;
                if(isSubstring(x, s)) {  
                    cout << i << "\n";
                    break;
                }
                else {
                    if(x.size() > 2 * s.size()){
                        cout << -1 << "\n";
                        break;
                    }
                }
            }   
        }
    }
}