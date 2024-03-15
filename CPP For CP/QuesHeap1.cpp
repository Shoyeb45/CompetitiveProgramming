#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;

    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0;
    for(int i=0; i<k; i++) {
        int n = pq.top();
        sum += n;
        cin >> n;
        pq.push(n/2);
    }
    cout << sum;

    // TC = O(n+k)

    return 0;
}