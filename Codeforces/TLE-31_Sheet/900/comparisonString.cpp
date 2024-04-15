#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<int> ans;
        int x = 10;
        ans.insert(x);
        int b = 0;
        loop(i, n) {
            if(s[i] == '<') {
                b++;
                ans.insert(x + b);
                cout << b << " " << x + b << "\n";
            } else {
                b--;
                ans.insert(x + b);
                cout << b << " " << x + b << "\n";
            }
        }
        cout << ans.size() << "\n";
    }
}