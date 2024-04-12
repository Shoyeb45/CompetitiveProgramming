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

        int count1 = 0;
        loop(i, s.size())   count1 += (s[i] == '1');

        if(count1 == s.size() || count1 == 0)    cout << "NET\n";
        else{

        }
    }
}
