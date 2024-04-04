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
        vector<int> a(n - 1);
        ll sum = 0 ;

        for(int i = 0 ; i < n - 1; i++) {
            cin >> a[i];
            sum += a[i];
        }

        cout << -1 * sum << endl;
    }
    
}