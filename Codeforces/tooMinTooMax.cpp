#include<bits/stdc++.h>
using namespace std;

int absolute(int a, int b) {
    int c = a - b;

    if(c >= 0)   return c;

    return -1*c;
}

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            p.push_back(temp);
        }
        sort(p.begin(), p.end());
        int max = absolute(p[0], p[n-1]) + absolute(p[n-1], p[1]) + absolute(p[1], p[n-2]) + absolute(p[n-2], p[0]);
        cout << max << "\n";
    }
    
}