#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int lcm(int x, int y, int i) {
    if(x * i % y == 0)  return X * i;
       lcm(x, y, i + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << lcm(max(a, b), min(a, b), 1) << endl;
    }
    
    return 0;
}
