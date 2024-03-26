#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        
        long long totalSum = (n) * (n + 1) / 2;
        long long sum1 = k * (k+1) /2;
        long long sum2 = totalSum - ((n - k) * (n - k + 1) / 2);

        if(x >= sum1 && x <= sum2)  cout << "YES\n";
        else    cout <<"NO\n";
    }
    
}