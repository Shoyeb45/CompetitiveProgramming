#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)  
using namespace std;
typedef long long ll;

int ans(int n, int mx, int size) {

        if(n == 1 || size == 1)  return 0;
        int count = 0;
        while (mx < n)
        {
            // count++;
            // count += min(mx, n - mx);
            // mx += min(mx, n - mx);
            if(2 * mx <= n) {
                count += mx;
                count++;
                mx = mx * 2;
            } else {
                // mx = mx * 2;
                count += (n - mx);
                count += ( (n - mx == 0) ? 0 : 1) ;
                break;
            }
        }
        return count;
}
int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, int> m;
        int mx = -1;
        loop(i, n) { 
            cin >> a[i];
           m[a[i]]++; 
           mx = max(m[a[i]], mx);
        }

        // for(const auto & pair : m) {
        //     if(mx <= pair.second)  mx = pair.second; 
        // }

        int b = ans(n, mx, m.size());
        cout << b << endl;
    }
    
}