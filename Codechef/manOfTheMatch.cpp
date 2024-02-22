#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
	    int a[22][2];
	    
	    for(int i=0; i<22; i++)
	        for(int j=0; j<2; j++)
	            cin >> a[i][j];

                int max = 0;
                int position = 0;
	            for(int i=0; i<22; i++) {
                    int sum = a[i][0] + a[i][1] * 20;

                    if(max <= sum) {
                        max = sum;
                        position = i+1;
                    }
                }

                cout << position << "\n";
	}
	
    return 0;
}
