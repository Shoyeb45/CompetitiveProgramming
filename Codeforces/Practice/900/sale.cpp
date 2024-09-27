
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    int price[n];

    for(int i=0; i<n; i++) {
        cin >> price[i];
    }

    vector<int> carry;
    for (int i=0; i<n; i++) {
        if(price[i] < 0) {
            carry.push_back(price[i]);
        }
    }
    
    int sum = 0;
    sort(carry.begin(), carry.end());
   if(m > carry.size()) {
   for(int i=0; i<carry.size() ; i++) {
        sum += carry[i];
   } 
    } else {
   for(int i=0; i<m; i++) {
        sum += carry[i];
   }
   }

   cout << -1 * sum;
    return 0;
}
