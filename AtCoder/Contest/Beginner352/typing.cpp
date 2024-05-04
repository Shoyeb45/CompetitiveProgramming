#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s;
    cin >> t;

    int i = 0, j = 0;

    while(i < s.size()) {
        if(s[i] == t[j]) {
            cout << j + 1 << " ";
            i++;
        }
        j++;
    }
    
    return 0;
}
