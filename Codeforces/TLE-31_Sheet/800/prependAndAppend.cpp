#include<bits/stdc++.h>
using namespace std;

void minLength(string s) {
    int low = 0, high = s.size() - 1;

    while (low <= high)
    {
        if((s[low] == '0' && s[high] == '0') || (s[low] == '1' && s[high] == '1')) {
            cout << (high - low) + 1 << "\n";
            return;
        }
        low++;
        high--;
    }
    cout << 0 << "\n";
}

int main () {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        minLength(s);
    }
    
}