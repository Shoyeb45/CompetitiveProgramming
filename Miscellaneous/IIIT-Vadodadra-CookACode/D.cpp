#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    vector<int> vivaan(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vivaan[i];
        sum += vivaan[i];
    }
    long long target = sum / n;
    long long current_sum = 0;
    int moves = 0;
    
    
    for (int i = 0; i < n; ++i) {
        current_sum += vivaan[i];
        
        
        if (current_sum == target) {
            current_sum = 0;
            moves++;
        } else if (current_sum > target) {
            
            current_sum = vivaan[i];
            moves++;
        }
    }
    
    
    cout << moves - 1 << endl; 
    return 0;
}