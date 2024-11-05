#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T; 
    while (T--) {
        int n;
        cin >> n; 
        vector<int> colors(n);
        unordered_map<int, vector<int>> positions; 

        for (int i = 0; i < n; i++) {
            cin >> colors[i];
            positions[colors[i]].push_back(i);
        }

        
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for (int length = 2; length <= n; length++) { 
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1; 
                
                if (colors[i] == colors[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + (j - i + 1);
                }
                
                dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
            }
        }

        cout << dp[0][n - 1] << endl; 
    }

    return 0;
}