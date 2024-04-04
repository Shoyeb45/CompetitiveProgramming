#include<bits/stdc++.h>

using namespace std;


int main() {
    set<int> s = {1, 1, 3, 2, 3};
    int it = *s.find(2);
    cout << s.size() << '\n';
    cout << it << '\n';
    int begin = *s.begin();
    // iterating through sets
    s.insert(9);
    for(auto it = s.begin(); it != s.end(); it++) cout << *it << '\n';
    cout << *s.rend();
}