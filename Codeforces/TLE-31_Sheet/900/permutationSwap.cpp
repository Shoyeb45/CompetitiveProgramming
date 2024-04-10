#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a;
        loop(i, n) { 
            int temp;
            cin >> temp;
            a.push_back(temp);
        }

        
        int ans = 0;

        loop(i, n) {
            ans = __gcd(ans, abs(a[i] - (i + 1)));
        }
        cout << ans << "\n";
    }

        return 0;
}