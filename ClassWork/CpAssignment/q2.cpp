#include<bits/stdc++.h>
using namespace std;

int main(){
    
        long long n ;
        cin >> n;
        long long m = n * n;
        bool isPrime[int(m+1)];

        for(long long i=0; i < m+1 ;i++){
            isPrime[i] = true;
        }
        
        isPrime[0] = false; isPrime[1]= false;

        for(long long i = 2 ; i * i <= m ; i++){
            if(isPrime[i]){
                for(int j = 2 * i; j <= m ; j = j + i){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        vector<int> prime;
        // cout << m;
        for(int i=2 ; i <= m ; i++){
            if(isPrime[i] == true) {
                prime.push_back(i);
            }
        }

        for(int i = 0 ; i < prime.size(); i++) {
            if(i % 2 == 0)
            cout << prime[i] << " ";
        }
}
