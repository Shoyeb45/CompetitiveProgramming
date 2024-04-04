#include<bits/stdc++.h>
using namespace std;

int main () {
    // Declaration
    stack<int> s;

    // Pushing element at the top
    s.push(2);
    s.push(4);
    // s = {4, 2}

    // Top - return top element
    cout << s.top() << endl;  // 4

    s.push(9); // s = {9, 4, 2}

    // Pop element - remove element from top
    s.pop();  //s = {4, 2}
    s.pop();  //s = {2}
    cout << s.top() << endl;  // 2

    s.pop();

    // Empty - true iff stack is empty
    if(s.empty())   cout << "Stack is empty.\n";

    s.push(43);
    s.push(12);
    s.push(12424);
    s.push(52432);

    // size :
    cout << s.size();
}
