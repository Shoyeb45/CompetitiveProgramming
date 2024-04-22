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
        loop(i, n)  
            cin >> a[i];

        map<int, int> mp;
        loop(i, n)  
            mp[a[i]]++;

        int ans = 0;
        for(auto & it : mp) {
            if(it.second >= 3) {
                if(it.second >= 6) {
                    ans += it.second/3;
                } else {
                    ans += 1;
                }
            } else {
                ans += 0;
            }
        }

        cout << ans << endl;
    }
}
