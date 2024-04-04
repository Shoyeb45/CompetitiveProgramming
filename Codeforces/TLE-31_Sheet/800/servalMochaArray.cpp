#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        loop(i, n)  cin >> a[i];
        int ans = false;
        
        loop(i, n ) {
            for(int j = i + 1; j < n; j++) {
                if(__gcd(a[i], a[j]) <= 2) {
                    ans = true;
                    break;
                }
                
            }
        }

        if(ans) cout << "YES\n";
        else    cout << "NO\n";
    }
    
}