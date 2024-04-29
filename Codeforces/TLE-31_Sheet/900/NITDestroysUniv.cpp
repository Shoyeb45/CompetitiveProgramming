#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int zero = 0;
        loop(i, n) { 
            cin >> a[i];
            zero += (a[i] == 0);
        }

        int i = 0;
        int ans = 0;
        
        if(zero == n) {
            cout << 0 << endl;
        } else {
            int leftIdx = 0;
            int rightIdx = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] > 0) {
                    leftIdx = i;
                    break;
                }
            }
            for(int i = n - 1; i >= 0; i--) {
                if(a[i] > 0) {
                    rightIdx = i;
                    break;
                }
            }

            bool ans = false;
            for(int i = leftIdx; i <= rightIdx; i++) {
                if(a[i] > 0) {
                    ans = true;
                } else {
                    ans = false;
                    break;
                }
            }

            if(ans)
                cout << 1 << endl;
            else 
                cout << 2 << endl;
        }
    }
    
    return 0;
}
