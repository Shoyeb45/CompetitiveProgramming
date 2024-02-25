#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> lan(n);
    for(int i = 0; i < n; i++) {
        cin >> lan[i];
    }   
    sort(lan.begin(), lan.end());
    double diff[n+1];
    double maxDif = -1;
    for(int i=-1, j=0; i<=n-1; i++) {
        if(i == -1) {
            diff[j] = lan[i+1] - 0;
            j++;
        }
        else if(i == n-1) {
            diff[j] = l - lan[i-1];
            j++;
        } else {
            diff[j] = lan[i+1] - lan[i];
            j++;
        }

        if(maxDif <= diff[j-1]) {
            maxDif = diff[j-1] ;
        }
    }  
    double secondMax = -1;

    for(int i=0; i<n+1; i++) {
        if(maxDif != diff[i] && secondMax <= diff[i]) {
            secondMax = diff[i];
        }
    }
    secondMax/2 <= maxDif/2 ? cout << maxDif/2 : cout << secondMax ;
    return 0;
}
