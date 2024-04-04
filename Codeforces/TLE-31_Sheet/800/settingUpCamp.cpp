#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if((b % 3 == 1 && c < 2) || (b % 3 == 2 && c < 1))  cout << -1 << "\n";
        else {
            ll tent = a + b/3;

            if(b % 3 == 1)  {
                tent++;
                c = c - 2; 
            } else if(b % 3 == 2) {
                tent++;
                c = c - 1;
            } 

            tent = c/3 + (c % 3);

            cout << tent << "\n";
        }
        
    }
    
}