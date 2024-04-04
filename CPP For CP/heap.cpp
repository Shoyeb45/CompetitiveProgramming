#include<bits/stdc++.h>
using namespace std;

int main () {
    // Declaration - by default element will arrange in decreasing order
    priority_queue<int> pq;

    // adding element
    pq.push(10);    //pq = {10}
    pq.push(4);     //pq = {10, 4}
    pq.push(19);    //pq = {19, 10, 4}

    // top - return the greatest element
    cout << pq.top() << "\n";

    // pop - will delete greaatest element
    pq.pop();       //pq = {10, 4}
    cout << pq.top() << "\n";

    // Sizeof priority queue
    cout << pq.size() << "\n";
    
    pq.pop();        //pq = {4}
    
    // empty - return true if empty
    if(pq.empty())  cout << "Priority queue is empty.\n";
    else    cout << "Priority queue is not empty.\n";
}