#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) { 
            cin >> a[i];
            sum += a[i];
        }
        if(sum % 3 == 0) {
            cout << 0 << "\n";
        } else {
            bool ans = true;
            for(int i=0; i<n ; i++) {
                if((sum - a[i]) % 3 == 0) {
                    cout << 1 <<'\n';
                    ans = false;
                    break;
                } 
            }

            if(ans) {
                if((sum+1) % 3 == 0){
                    cout << 1 << '\n';
                } else if( (sum % 3) == 1 ) {
                    cout << 2 << '\n';
                } else {
                    cout << (sum % 3) << '\n';
                }
                }
        }
    }
    
}