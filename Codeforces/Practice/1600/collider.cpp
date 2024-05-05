#include<bits/stdc++.h>
using namespace std;
#define MAX 100002

vector<int> prime(MAX, 1);
vector<int> primeDivisor[MAX];

void sieve() {
    for(int i = 2; i<= MAX; i++) {
        if(prime[i]) {
            for(int j = 2 * i; j <= MAX; j += i) {
                prime[j] = 0;
                primeDivisor[j].push_back(i);
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    sieve();

    vector<int> collider(n+1, 0);
    
    while (m--) {
        char c;
        int k;
        cin >> c >> k;

        if(c == '+') {
            if(collider[k] == k) {
                cout << "Already on\n";
                continue;
            }

            if(collider[k]) {
                cout << "Conflict with " << collider[k] << "\n";
                continue;
            }

            for(int i = 0 ; i < primeDivisor[k].size(); i++) {
                int divisor = primeDivisor[k][i];
                if(collider[divisor]) {
                    cout << "Conflict with " << collider[divisor] << "\n";
                    goto end;
                }
            }

            for(int i = 0 ; i < primeDivisor[k].size(); i++) {
                int divisor = primeDivisor[k][i];
                collider[divisor] = k;
            }

            collider[k] = k;
            cout << "Success\n";
        } else {
            if(collider[k] != k) {
                cout << "Already off\n";
            } else {
                for(int i = 0 ; i < primeDivisor[k].size(); i++) {
                    int divisor = primeDivisor[k][i];
                    collider[k] = divisor;
                }
                collider[k] = 0;
                cout << "Success\n";
            }
        }
        end: ;
    }

}