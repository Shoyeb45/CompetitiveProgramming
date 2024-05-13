#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declaration 
    queue<int> q;
    // We can only access first element and insert at last position

    // push - insert at last position
    q.push(3);   // {3}
    q.push(5);   // {3, 5}
    q.push(10);  // {3, 5, 10}

    // front - access first element
    cout << q.front() << endl;

    // Pop - remove element from the front
    q.pop(); // {5, 10}
    cout << q.front() << endl;

    // size 
    cout << q.size() << "\n";

    q.pop(); // {10}
    q.pop();

    // Empty - return true
    if(q.empty())   cout << "Queue is empty.\n";
}