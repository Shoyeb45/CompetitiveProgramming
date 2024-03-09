#include<bits/stdc++.h>
using namespace std;

long long modExpo(long long b, long long p, long long m){
        if(p == 0)
        return 1;
        if(p == 1)
        return b % m;
        long temp = modExpo(b, p/2, m);

        if(p % 2 == 1){
            return (temp * temp * b) % m;
        }else{
            return (temp * temp ) % m;
        }
}
        
int main() {
        long long b;
        long long p;
        long long m;
        cin >> b >> p >> m;

       cout << modExpo(b, p, m);
}

