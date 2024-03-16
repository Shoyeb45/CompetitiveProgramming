#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)  {
        int temp; 
        cin >> temp;
        if(temp < 0) {
            a.push_back(-1 * temp);
        } else {
            a.push_back(temp);
        }
    }

    sort(a.begin(), a.end());

    cout << a[0];
}