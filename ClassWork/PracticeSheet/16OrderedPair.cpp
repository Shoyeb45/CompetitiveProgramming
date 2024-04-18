#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int n;
    cin >> n;
   
    for(int i = 1; i < n; i++) {
        for(int j = i; j <= n; j++) {
            if(i == j)  {
                cout << "(" << i << "," << j << ")" << endl;    
            } else {
                cout << "(" << i << "," << j << ")" << endl;    
                cout << "(" << j << "," << i << ")" << endl;
            }
        }
    }
     
}
