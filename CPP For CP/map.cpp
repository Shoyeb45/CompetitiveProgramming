#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declaration : key and value pair
    map<int, int> m;

    // counting number of occurence in vector
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
        m[a[i]]++;     // At ith pair it will increment by 1
    }

    // prinitng occurence
    for(const auto & pair : m) {
        cout << "Occurence of " << pair.first << " is " << pair.second << endl;
    }

        cout << m[9] ;
}