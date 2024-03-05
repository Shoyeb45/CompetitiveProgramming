#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++)  cin >> a[i];

    int Ansi = 0, Ansj = n-1;

    for(int i = 0; i <= n-2; i++) {
        if(a[i] > a[i+1]) {
            Ansi = i+1;
            break;
        }
    }   

    int pt = 0;

    for(int i = Ansi+1; i <= n-2  ; i++) {
        if(a[i] < a[i+1] && a[i] < a[i-1]) {
            pt = i;
        }
    }
    for(int j = n - 1; j > pt; j--) {
        if(a[j] < a[j-1]) {
            Ansj = j-1;
            break;
        }
    }   

    cout << Ansj-Ansi+1;
}