#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string reverseStr(string& str)
{
    int n = str.length();
    string reverse = "";
    for (int i = n-1; i >= 0 ; i--) reverse += str[i];

    return reverse;
}
int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string A;
        cin >> A;
        string reverseA = reverseStr(A);
       
            if(A.size() == 1)   cout << A+A << "\n";
            else if(A[A.size()-1] < A[0]) cout << reverseA + A << '\n';
            else    cout << A << '\n';
    
}
}