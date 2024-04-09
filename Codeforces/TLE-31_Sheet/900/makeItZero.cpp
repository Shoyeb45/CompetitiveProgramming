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
        loop(i, n)  cin >> a[i];

        if(n % 2 == 0) {
            cout << 2 << "\n" << 1 << " " << n <<"\n" << 1 << " " << n << "\n"; 
        } else {
            // if(n > 3) {
                cout << 4 << "\n";
                cout << 1 << " " << n - 1 << "\n";
                cout << 1 << " " << n - 1 << "\n";
                cout << n - 1 << " " << n << "\n";
                cout << n - 1 << " " << n << "\n";
            // } else {
            //     cout << 4 << endl;
            //     cout << 1 << " " << 2 << "\n";
            //     cout << 1 << " " << 2 << "\n";
            //     cout << 2 << " " << 3 << "\n";
            //     cout << 2 << " " << 3 << "\n";

            // }
        }
    }
}
