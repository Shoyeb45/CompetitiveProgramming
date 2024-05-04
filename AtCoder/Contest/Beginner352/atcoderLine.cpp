#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if((z > x && z < y) || (z > y && z < x))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
