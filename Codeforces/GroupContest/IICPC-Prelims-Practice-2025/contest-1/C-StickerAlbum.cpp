#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = b - a + 1;
    vector<double> dp(n + b + 5, 0.0), suffix(n + b + 10, 0.0);

    for(int i=n- 1; i >= 0; i--){
        if(a == 0) {
            // agar a = 0 hai to ek move 0 hamesha self-loop karega 
            double total = suffix[i+1] - suffix[i+b+1];
            dp[i] = (m+total )/(m-1);
        }else{
            double total  = suffix[i+a] - suffix[i+b+1];
            dp[i]=(m+total )/m;
        }
        suffix[i] = dp[i] + suffix[i+1];
    }

    cout<<fixed<< setprecision(6)<< dp[0] << endl;
    return 0;
}
        
