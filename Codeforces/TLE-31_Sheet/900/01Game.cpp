#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int ones = 0;
        for(char ch: s) {
            ones += (ch == '1');
        }
        int zeroes = s.size() - ones;

        if(ones == 0 || zeroes == 0) {
            cout << "NET\n";
        } else {
            int ans = min(ones, zeroes);
            if(ans % 2 == 1)
                cout << "DA\n";
            else
                cout << "NET\n";
        }
    }
    
    return 0;
}
