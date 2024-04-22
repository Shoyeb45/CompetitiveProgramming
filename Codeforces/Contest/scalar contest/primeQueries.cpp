#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    long long L, R, k, s, mn, mx;
    cin >> L >> R >> k >> s >> mn >> mx;
    int n = sqrt(R);

    // Array for 2 to root(R)
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Checking prime between 2 to root(R)
    for (ll i = 2; (ll)(i * i) <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Checking the prime numbers between L to R
    vector<bool> primeBetween(R - L + 1, true);
    primeBetween[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            ll strt =   max((L + i - 1) / i * i, (long long) (i * i));
            for (long long j = strt; j <= R; j += i) {
                primeBetween[j - L] = false;
            }
        }
    }

    vector<ll> p;
    for(ll i = 1; i < R - L + 1 ; i++) 
        if(primeBetween[i]) p.push_back(i + 1);
    
    
    int check = p[k-1];

    int digits = (int)(log10(check)) + 1;
    int sumPrime = 0;
    int sumNonPrime = 0;
    int temp = check;
    
    while(temp >= 1) {
        int d = temp % 10;
        if(isPrime[d])    sumPrime++;
        else sumNonPrime++;
        temp /= 10;
    }

    if((digits >= mx && digits <= mn) && (sumPrime <= s) && (sumNonPrime <= s)) cout << check << "\n";
    else    cout << -1 << "\n";
    return 0;
}
