// Find the prefix sum of the array of given number

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> prefixSum(n);
    int a;
    cin >> a;
    v.push_back(a);
    v.push_back(v[0]);

    for(int i=1; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        prefixSum.push_back(prefixSum[i-1] + v[i]);
    }

    for (int i=0; i<n; i++) {
        cout << prefixSum[i] <<" " ;
    }
    for (int i=0; i<n; i++) {
        cout << v[i] <<" " ;
    }
    return 0;
}
