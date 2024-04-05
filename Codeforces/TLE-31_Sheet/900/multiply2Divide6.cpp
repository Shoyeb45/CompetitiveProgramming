#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int ans(ll n) {
    int count = 0;

    while(n != 1) {
        count++;
        if(n % 6 == 0)   n /= 6;
        else {
            n *= 2;
            if(n % 6 != 0)   return -1;
        }
    }
    return count;
}


int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1)  cout << 0 << "\n";
        else {
                int answer = ans(n);
                   cout << answer << endl;
            }
        }
}
