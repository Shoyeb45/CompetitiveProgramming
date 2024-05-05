
#include<bits/stdc++.h>

using namespace std;

int main() {
    string a, b ,c;
    cin >> a >> b >> c;
    bool isEqual = false;
    

    if(a.size() + b.size() != c.size()) cout << "NO";
    else {
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      sort(c.begin(), c.end());
      int j=0, k=0;

      for(int i=0 ; i<c.size(); i++) {
        if(c[i] == a[j]) {
            isEqual = true;
            j++;
        } else if (c[i] == b[k]) {
            isEqual = true;
            k++;
        } else {
            isEqual = false;
        }
      }

      if(isEqual)   cout << "YES";
      else  cout << "NO"; 
    }

    return 0;
}
