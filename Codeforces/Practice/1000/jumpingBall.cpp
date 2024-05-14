#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    string a;   
    cin >> a;
    ll ans = 0;
    if(a[0] == '<') {
        int i = 0;
        while(i < n && a[i] == a[0]) {
            ans++;
            i++;
        }
    }
    if(a[n - 1] == '>') {
        int i = n - 1;
        while(i >= 0 && a[i] == a[n - 1]) {
            ans++;
            i--;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
