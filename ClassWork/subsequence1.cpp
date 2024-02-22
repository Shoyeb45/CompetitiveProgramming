// given two string one is original and one is subsequence , return whether the subsequence is valid subsequence or not 

#include<bits/stdc++.h>
using namespace std;

bool isSubsequ(string o, string ss) {
    int i=0, j=0;

    while(i < o.size() && j < ss.size()) {
        if(o[i] == ss[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }

    if(j == ss.size()) {
        return true;
    } 

    return false;
    // for(int i=0; i<ss.size(); ) {
    //     for(int j=i; j<o.size(); j++) {
    //         if(ss[i] == o[j]) {
    //             i++;
    //             j = j + i;
    //             ans = true;
    //             break;
    //         } else {
    //             ans = false;
    //         }
    //     }
    // }
    // return ans;
}

int main() {
    string o, ss;
    cin >> o >> ss;
    cout << isSubsequ(o, ss);
}