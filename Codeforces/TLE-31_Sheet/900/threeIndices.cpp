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
        int n;
        cin >> n;
        vector<int> a(n);
        loop(i, n)  cin >> a[i];

        int idx1 = 0, idx2 = 0, idx3 = 0;
        bool check1 = false;
        bool check2 = false;

        for(int j = 1; j < n -1; j++) {
            check1 = false, check2 = false;
            for(int p = j - 1; p >= 0; p--) {
                if(a[p] < a[j]) {
                    check1 = true;
                    idx1 = p;
                    break;
                } else 
                    check1 = false;
            }

            for(int p = j + 1; p < n; p++) {
                if(a[p] < a[j]) {
                    check2 = true;
                    idx3 = p;
                    break;
                } else 
                    check2 = false;
            }
            if(check1 && check2) {
                idx2 = j;
                break;
            }
        }


        if(check1 && check2) {
            cout << "YES\n";
            cout << idx1 + 1 << " " << idx2 + 1 << " " << idx3 + 1 << "\n";
        }
        else 
            cout << "NO\n";
    }
    
    return 0;
}
