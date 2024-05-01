#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int evaluate(int n, int x) {
    if(n == 0) {
        return 0;
    }

    return pow(x, n - 1) + evaluate(n - 1, x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    
    int ans = evaluate(n, x);
    cout << ans << "\n";
    return 0;
}
