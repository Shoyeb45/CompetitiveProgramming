#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int water[n];
        int sum = 0;
        for(int i=0;i <n; i++) {
            cin >> water[i];
            sum += water[i];
        }
        int finalLevel = sum/n;
        int sum2 = 0;
        int ans = true;
        for(int i=1; i<=n; i++) {
            int value = water[i-1];
            sum2 += value;
        if(sum2 < i * finalLevel) ans = false;
        }


        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    
}