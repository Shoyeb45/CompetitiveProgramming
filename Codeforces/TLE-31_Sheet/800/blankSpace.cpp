#include<bits/stdc++.h>
using  namespace std;

int main () {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)  cin >> a[i];

        int maxLength = 0;
        int j = 0;
        for(int i = 0; i <= n - 1; i++) {
            int cnt = 0;
            if(!a[i]) {
                for(j = i; ; j++){
                    if(a[j])    break;
                    else if(j == n - 1 && a[j] == 0) {
                        cnt++;
                        break;
                    }
                    else    cnt += 1;
                }
            }
            if(maxLength <= cnt)    maxLength = cnt;
        }

        if(n == 1 && a[0] == 0) cout << 1 << '\n';
        else   cout << maxLength << '\n';
    }
    
}