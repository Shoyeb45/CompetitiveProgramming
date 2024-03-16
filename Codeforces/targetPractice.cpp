#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--)
    {      
        int count = 0;
        for (int i = 1; i <= 10; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 10; j++) {
                if(s[j] == 'X') {
                    if((i == 1 || i == 10) && (j >= 0 || j <= 9))   count += 1;
                    else if (i == 2 || i == 9) { 
                        if((j >= 1 && j <= 8))  count += 2;
                        else    count += 1;
                    }
                    else if (i == 3 || i == 8) {
                        if(j >= 2 && j <= 7)    count += 3;
                        else if(j == 1 || j == 8)   count += 2;
                        else    count += 1;
                    }
                    else if (i == 4 || i == 7) { 
                        if(j >= 3 && j <= 6)    count += 4;
                        else if(j == 2 || j == 7)   count += 3;
                        else if(j == 1 || j == 8)   count += 2;
                        else    count += 1;
                    }
                    else if (i == 5 || i == 6)  {
                        if(j >= 4 && j <= 5)    count += 5;
                        else if(j >= 3 && j <= 6)    count += 4;
                        else if(j == 2 || j == 7)   count += 3;
                        else if(j == 1 || j == 8)   count += 2;
                        else    count += 1;
                    }
                }
            }
        }
        cout << count <<'\n';
    }
            
}