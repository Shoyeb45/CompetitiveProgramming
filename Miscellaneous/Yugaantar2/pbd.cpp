#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    // Declaration of ordered_multiset as 'ss'
    ordered_multiset<int> ss;

    // Inserting elements into 'ss'
    ss.insert(5);
    ss.insert(2);
    ss.insert(7);
    ss.insert(2); // Allows duplicates
    ss.insert(1);



    // Displaying elements 
    cout << "Elements in the ordered_multiset: ";
    for (auto it : ss) { // 1 2 2 5 7
        cout << it << " ";
    }
    cout << endl;

    // Counting elements less than 5 using order_of_key
    cout << "Elements less than 5: " << ss.order_of_key(5) << endl; // 3

    // Deleting an element, e.g., deleting value 2
    auto it = ss.find_by_order(ss.order_of_key(2)); // Find iterator to the element 2
    if (it != ss.end()) {
        ss.erase(it); // Erase the found element O(log n)
        cout << "Element 2 removed from the ordered_multiset." << endl;
    } else {
        cout << "Element not found in the ordered_multiset." << endl;
    }

    ss.clear();

    ss.insert(4);
    ss.insert(4);
    ss.insert(4);
    ss.insert(6);
    
    cout << ss.order_of_key(6) << "\n";
    it = ss.find_by_order(ss.order_of_key(4));
    if (it != ss.end()) {
        ss.erase(it);
    }
    cout << ss.order_of_key(6) << "\n";
    return 0;
}