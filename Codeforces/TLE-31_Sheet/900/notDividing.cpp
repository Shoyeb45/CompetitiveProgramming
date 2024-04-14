#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n ;

        vector<int> a(n);

        loop(i, n) {
            cin >> a[i];
            a[i] += (a[i] == 1);
        }
        
        for(int i = 1; i < n; i++) {
            if(a[i] % a[i - 1] == 0) {;
                a[i]++;
            }
        }
        
        loop(i, n) {
            cout << a[i] << " " ;
        }
        cout << "\n";
    }

        return 0;
}