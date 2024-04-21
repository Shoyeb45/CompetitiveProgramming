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
        vector<int> a(n);

        ll sum = 0;
        int zeroCnt = 0, oneCnt = 0;
        loop(i, n) {
            cin >> a[i];
            sum += a[i];
            zeroCnt += (a[i] == 0);
            oneCnt += (a[i] == 1);
        }

        ll ans = 0;
        
        ans = pow(2, zeroCnt) * oneCnt;

        cout << ans << "\n";
    }
    
}
