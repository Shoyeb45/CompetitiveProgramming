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
            if(n > 3) {
                cout << 4 << "\n";
                cout << 1 << " " << n - 2 << "\n";
                cout << 1 << " " << n - 2 << "\n";
                cout << n - 1 << " " << n << "\n";
                cout << n - 1 << " " << n << "\n";
            } else {
                if(a[0] ^ a[1] ^ a[2] == 0) {
                    cout << 1 << endl;
                    cout << 1 << " " << 3 <<endl;
                } else if(a[0] ^ a[1] == a[2]) {
                    cout << 2 << endl;
                    cout << 1 << " " << 2 << "\n";
                    cout << 1 << " " << 3 << "\n";
                } else {
                    cout << 2 << endl;
                    cout << 2 << " " << 3 << "\n";
                    cout << 1 << " " << 3 << "\n";

                }
            }
        }
    }
}
