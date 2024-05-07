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

    vector<int> a(n);
    loop(i, n)  cin >> a[i];
    ll sum = 0;
    loop(i, n) {
        ll sum1 = 0;
        for(int j = i; j < n; j++) {
            sum1 += a[i];
        }
        
    }
    
    return 0;
}
