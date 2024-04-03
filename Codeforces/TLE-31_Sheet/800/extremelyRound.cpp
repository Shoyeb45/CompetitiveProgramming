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
            int digits = (int)(log10(n)) + 1;
            int  mult = 10;
            loop(i, digits - 2) mult *= 10; 

            int x = n/mult;
            cout << 9*(digits - 1) + x  << "\n";
        }
    }
    
}