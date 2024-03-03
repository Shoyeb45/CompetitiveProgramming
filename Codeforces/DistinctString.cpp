#include<bits/stdc++.h>
using namespace std;

int  main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string p = s+s;
        vector<string> subStr;
        subStr.push_back(s);

        int cnt = 1;
        for(int i=1; i <= n ; i++) {
            string temp = p.substr(i, n);
            subStr.push_back(temp);
            if(subStr[i] == subStr[i-1] || subStr[i] == subStr[0]) {
                break; 
            } else {
                cnt++;
            }
        }

        cout << cnt <<'\n';
    }
    
    return 0;
}