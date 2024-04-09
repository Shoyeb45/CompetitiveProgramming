#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int cnt = 0, ans = 0;
        
        if((n & 1) == 1)    cout << 1 << endl;
        else {
            for(int i = 1; ; i++) {
                if(n % i != 0)  {
                    cout << i - 1 << endl;
                    break;
                }
            }
        }

    }
    return 0;
}
