// Implementing dynamic array
#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
#define initial_capacity 5
#define growth_factor 2

class Array {
    int capacity;
    int sz;
    int *data;
    
    public:
        Array() {
            sz = 0;
            capacity = initial_capacity;
            data = (int*)calloc(capacity, sizeof(int));
            if(!data)
                throw bad_alloc();
        };
        ~Array() {
            free(data);
        };
    
    private:    
    void double_capacity() {
        int* new_data = (int*)realloc(data, growth_factor * capacity * sizeof(int));
        if(!new_data) {
            throw bad_alloc();
        }
        data = new_data;
        capacity = growth_factor * capacity;
    }

    public:
    // Inserting element at first index
    void preappend(int val) {
        if(sz == capacity) {
            double_capacity();
        }
        for(int i = sz - 1; i >= 0 ; i--) {
            data[i + 1] = data[i];
        }
        data[0] = val;;
        sz++;
    }

    // Inserting element at end 
    void append(int val) {
        if(sz == capacity) {
            double_capacity();
        }
        data[sz] = val;
        sz++;
    }

    // Insert element at any index
    void insert(int val, int index) {
        if(index < 0 || index > sz) {
            throw std::out_of_range("Index out of bounds");
        }

        if(sz == capacity) {
            double_capacity();
        }
        if(index == 0) {
            this->preappend(val);
            return;
        } else if (index == sz) {
            this->append(val);
            return;
        }


        // Making place for new value
        for(int i = sz - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = val;
        sz++;
        return;
    }

    // Remove element at any index
    void remove(int index) {
        if(index < 0 || index >= sz) {
            throw std::out_of_range("Index out of bounds");
        }
        if(index == sz - 1) {
            data[index] = 0;
            sz--;
            return;
        }

        for (int i = index; i < sz - 1; ++i) {
            data[i] = data[i + 1];
        }
        sz--;
        return;
    }

    // Get the middle element of array
    int middle_element() {
        if(!sz) {
            throw out_of_range("Array is empty");
        }
        return data[sz/2];
    }

    // First occurence of any element - returns index if present else -1
    int first_occurence(int target) {
        for(int i = 0; i < sz; i++) {
            if(data[i] == target)
                return i;
        }
        return -1;
    }

    // Resize the array
    void resize(int n) {
        if(n < 0) {
            throw invalid_argument("Size of the array can't be negative");
        }

        if(n > capacity) {
            double_capacity();
        }

        if(n > sz) {
            for(int i = sz; i < n; i++) {
                data[i] = 0;
            }
        }
        sz = n;
        return;
    }

    // Reverse the array
    void Reverse() {
        for(int i = 0; i <= (sz/2) - 1; i++) {
            int temp = data[i];
            data[i] = data[sz - i - 1];
            data[sz - i - 1] = temp;
        }
    }

    // Merge two arrays - return new merged array
    Array merge(Array a) {
        Array c;

        loop(i, this->sz) {
            c.append(data[i]);
        }

        loop(i, a.size()) {
            c.append(a[i]);
        }
        return c;
    }

    // Rotating the array by k position
    void rotate(int k) {
        if(sz == 0)
            return;
        k = k % sz;
        if(k == 0) 
            return;

        this->Reverse();
        reverse(data, data + k);
        reverse(data + k, data + sz);
    }

    // Interleaving two arrays - it wiil return new interleaved array
    Array interleave(Array a) {
        Array c;
        int i = 0, j = 0;
        while(i < this->sz && j < a.size()) {
            c.append(this->data[i++]);
            c.append(a[j++]);
        }

        while(j < a.size()) {
            c.append(a[j++]);
        }
        while(i < this->sz) {
            c.append(this->data[i++]);
        }
        return c;
    
    }
    
    // Spliting the array in two arrays at specified index
    void split(int k) {
        if(k < 0 || k >= this->sz) {
            throw out_of_range("Index out of bound");
        }
        Array a;
        Array b;
        loop(i, this->sz) {
            if(i < k) {
                cout << this->data[i] << ' ';
            } else {
                if(i == k)
                    cout << '\n';
                cout << this->data[i] << ' ';
            }
        }
    }
    // Get size of the array
    int size() {
        return this->sz;
    }

    // Check if array is empty or not
    bool empty() {
        return this->sz == 0;
    }

    // Method for displaying
    void display () {
        for(int i = 0; i < this->sz; i++) {
            cout << data[i] << " ";
        }
        cout << '\n';
    }

    // Overlaoding bracket operators for accessing elements
    int& operator[](int index) {
        if(index < 0 || index >= sz) {
            throw out_of_range("Index out of bound.");
        }
        return data[index];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Array a;
    // cout << (a.empty()? "YES\n" : "NO\n");
    // a.preappend(13);
    // a.append(90);
    // a.append(3);
    // a.preappend(12);
    // a.preappend(8);
    // a.append(13);
    // // a.display();

    // a.insert(69, 2);
    // a.insert(1, 0);
    // a.insert(43, a.size());
    // cout << a.size() << '\n';
    // // a.display();
    // cout << '\n';

    // // a.remove(a.size() - 1);
    // a.display();
    // cout << "Middle element when odd numbers: " << a.middle_element() << '\n';
    // a.remove(4);
    // a.display();
    // cout << "Middle element when even numbers: " << a.middle_element() << '\n';
    // cout << "Index of first occurence of 3: " << a.first_occurence(3) << '\n';

    // // Resizing
    // Array b;
    // b.append(12);
    // b.append(43);
    // cout << "Size of b: " << b.size() << '\n';
    // b.resize(6);
    // cout << "After resizing by 6\n";
    // loop(i, b.size()) {
    //     cout << b[i] << " ";
    // }
    // cout << '\n';
    // b.resize(3);
    // loop(i, b.size()) {
    //     cout << b[i] << " ";
    // }
    // cout << '\n';
    // b[b.size() - 1] = 32;
    // b.display();
    // cout << b.size() << '\n';
    // b.Reverse();
    // b.display();
    // b.append(3);
    // b.append(3);
    // b.append(45);
    // b.preappend(10);
    // b.display();
    // b.Reverse();
    // b.display();

    // Array d = a.merge(b);
    // cout << "Size of merged array: " << d.size() << '\n';
    // // d.rotate(3);
    // d.rotate(6);
    // d.display();
    
    // Array one;
    // one.append(1);
    // // one.append(3);
    // one.append(5);
    // Array two;
    // two.append(2);
    // two.append(4);
    // two.append(6);
    // cout << '\n' << "interleaving\n";
    // Array inter = one.interleave(two);
    // inter.display();

    Array test;
    test.append(13);
    test.append(14);
    test.append(15);
    test.append(16);
    test.append(19);
    test.display();
    // vector<Array> sp = test.split(1);
    // loop(i, 2) {
    //     loop(j, sp[i].size()) {
    //         cout << sp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    test.split(3);
    return 0;
}
