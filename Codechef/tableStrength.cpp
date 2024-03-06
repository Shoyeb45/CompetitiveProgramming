#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> a;
	    
	    for(int i=0; i<n; i++)  {
	        int temp;
	        cin >> temp;
	        a.push_back(temp);
	    }
	    
	    sort(a.begin(), a.end());
	    int weight = 0;
	    int maxWt = -9;
	    for(int i = n - 1 , j = 1; i >= 0 ; i--, j++) {
	        weight = a[i] * j;
	        if(maxWt <= weight) {
	            maxWt = weight;
	        }
	    }
	    cout << maxWt << "\n";
	}

}
