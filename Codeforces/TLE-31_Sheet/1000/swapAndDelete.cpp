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
        int one = 0;
        loop(i, s.size())   one += (s[i] == '1');
        int zero = s.size() - one;

        loop(i, s.size() + 1) {
            if(i == s.size() || zero == 0 || one == 0)  {
                cout << s.size() - i << endl;
                break;
            } 
            else if(zero > 0 && s[i] == '1') zero--;
            else if(one > 0 && s[i] == '0') one--;
        }
    }
    return 0;
}
