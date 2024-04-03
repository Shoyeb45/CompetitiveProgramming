#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        
        if(n <= 10) cout << n << endl;
        else {
            cout << 10 + (n - 10)/10  << "\n";
        }
    }
    
}