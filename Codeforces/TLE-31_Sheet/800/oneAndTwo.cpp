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
        vector<int> a(n);
        ll twos = 0;

        loop(i, n) { 
            cin >> a[i];
            twos += (a[i] == 2);
        }

        if(!twos)   cout << 1 << "\n";
        else if(twos == n && n % 2 == 0)  cout << n/2 << "\n";
        else {
            if(twos % 2 == 1)   cout << -1 << "\n";
            else {
                ll cnt = 0;
                loop(i, n) {
                    cnt += (a[i] == 2);
                    if(cnt == twos/2)   {
                        cout << i + 1 << "\n";
                        break;
                    }
                }
            }
        }
    }
    
}