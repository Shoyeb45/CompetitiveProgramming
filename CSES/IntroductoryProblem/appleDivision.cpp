#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

ll apples(vector<ll> &p, ll idx, ll sum1, ll sum2) {
    if(idx == p.size())
        return abs(sum1 - sum2);
    
    return min(apples(p, idx + 1, sum1 + p[idx], sum2), apples(p, idx + 1, sum1, sum2 + p[idx]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> p(n);
    loop(i, n)  cin >> p[i];

    cout << apples(p, 0, 0, 0);
    
    return 0;
}
