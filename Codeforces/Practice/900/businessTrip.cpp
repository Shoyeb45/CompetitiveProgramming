#include<bits/stdc++.h>
using namespace std;

int  main() {
    int k;
    cin >> k;
    int a[12];
    for(int i=0; i<12; i++) cin >> a[i];

    sort(a, a + 12);
    int tempSum = 0;
    int ans = 0;
    for(int i=11; i>=0; i--) {
        tempSum += a[i];
        if(tempSum >= k ) {
            ans = 12 - i;
            break;
        }
    }
    if(k == 0) cout << 0 ;
    else if(ans == 0) cout << -1;
    else cout << ans;

    return 0;
}