#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
ll power(ll b, ll p, ll m){
        if(p == 0)
        return 1;
        if(p == 1)
        return b % m;
        ll temp = power(b, p/2, m) % m;

        temp = (temp * temp) % m;
        if(p % 2 == 1){
            return (temp * b) % m;
        }else{
            return temp ;
        }
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    cin >> s >> k;
    map<char, int> mp;
    for(char & ch: s)
        mp[ch]++;
    int n = mp.size();

    int x = power(n/2, k, mod);
    x = n % 2 == 0 ? x : x * k;
    cout << x;
    return 0;
}
