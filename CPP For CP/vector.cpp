#include<bits/stdc++.h>

using namespace std;
int sum(vector<int> &v) {
    int sum2=0;
    for(int i=0; i<v.size(); i++) {
        sum2 += v[i];
    }
    return sum2;
}

int main() {
    int n;
    cin >> n ;
    // when we don't know predefined size 
    vector<int> arr;
    vector<string> str;

    // when we know the predefined size

    vector<int> arr1(n);

}