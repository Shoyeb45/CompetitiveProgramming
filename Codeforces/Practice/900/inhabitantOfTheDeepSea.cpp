#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;



int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        vector<ll> prefixArr;

        loop(i, n)  cin >> a[i];
        prefixArr.push_back(a[0]);

        for(int i = 1; i < n; i++) {
            prefixArr.push_back(prefixArr[i - 1] + a[i]);
        }

        int ans = 0;
        if(prefixArr[n - 1] <= k)   ans = n;
        else {
            ll left = (k % 2 == 0) ? k/2 : k/2 + 1;
            ll right = k/2;
            if(n % 2 == 0) {
                ll sum = 0;
                for(int i = 0; i < n/2; i++) {
                    sum += a[i];
                    if(sum <= left)
                        ans++;
                    else 
                        break;
                }
                    sum = 0;
                for(int i = n - 1; i >= n/2; i--) {
                    sum += a[i];
                    if(sum <= right) 
                        ans++;
                    else 
                        break;     
                }
            } else {
                ll sum = 0;
                for(int i = 0; i <= n/2; i++) {
                    sum += a[i];
                    if(sum <= left) 
                        ans++;
                    else {
                        a[i] -= (left - (sum - a[i]));
                        break;
                    }
                }
                sum = 0;
                for(int i = n - 1; i >= n/2; i--) {
                    sum += a[i];
                    if(sum <= right)    ans++;
                    else    break;
                }
            }
        }
        
        cout << ans << "\n";
    }
}
