#include<bits/stdc++.h>
using namespace std;

// Maximum size and Maximum Threshold for hashmap
#define MAX_THRESHOLD 0.4
#define MAX_CAPACITY 16

/**
 * HashTable implementation -*- C++ -*-
 * HashTable implementation using separate chaining. Using in-built function hash.
 */
template<typename K, typename V>
class HashTable {

    // Entry class for storing key, value and hashcode of key.
    class Entry {
    public:
        K key;
        V value;
        int hash_code;
        Entry(K key, V value, int hc) {
            this->key = key;
            this->value = value;
            this->hash_code = hc;
        }
    };

    private:
        int sz;
        int capacity;
        vector<vector<Entry>> arr;
    
    public:

    /**
     * Public constructor to initialize hash map.
     * We can initialize hashmap with any dataa type as key and give any data type as value.<hr>
     */
    HashTable() {
        sz = 0;
        capacity = MAX_CAPACITY;
        arr.resize(capacity);
    }

    /**
     * Inserting Key and value into Hash Table.
     * The average time complexity of inserting operation will be O(1)
     * If the key is already present then it will update the value with new given value
     * @param k  key
     * @param v  value
     */
    void insert(K key, V value) {
        if((double)sz / capacity > MAX_THRESHOLD) {
            this->resize();
        }

        int idx = get_index(hash(key));
        for(int i = 0; i < arr[idx].size(); i++) {
            if(arr[idx][i].key == key) {
                arr[idx][i].value = value;
                return;
            }
        }
        Entry new_entry(key, value, hash(key));
        arr[idx].push_back(new_entry);
        sz++;
    }

     /**
     * Get size of the hash table.
     */
    int size() {
        return sz;
    }

    /**
     * Checks if hash map is empty or not.
     * @returns
     * true, if empty
     */
    bool empty() {
        return sz == 0;
    }

     /**
     * This will check wheter the key is already present in hashtable or not.
     * @param key
     * @return
     * true, if present
     */
    bool find(K key) {
        int idx = get_index(hash(key));
        for(int i = 0; i < arr[idx].size(); i++) {
            if(arr[idx][i].key == key) {
                return true;
            }
        }
        return false;
    }

    /**
     * Deletes the particulatr  key from the hash table.
     * @param key
     * @throw 
     * std:: underflow_error()
     */
    void delKey(K key) {
        int idx = get_index(hash(key));
        auto &bucket = arr[idx];
        for(auto it = bucket.begin(); it != bucket.end(); it++) {
            if(it->key == key) {
                bucket.erase(it);
                sz--;
                return;
            }
        }
        throw std:: underflow_error("Map does not have key \"" + key + "\" ");
    }

    /**
     * Getting the value of particular element by passing key as argument.
     * @param key
     * @return
     * Returns value if key is present else it will create new key and will return default value.
     */
    V& operator[](K key) {
        int idx = get_index(hash(key));
        for(int i = 0; i < arr[idx].size(); i++) {
            if(arr[idx][i].key == key) {
                return arr[idx][i].value;
            }
        }
        if((double) sz / capacity > MAX_THRESHOLD) {
            this->resize();
        }
        idx = get_index(hash(key));
        Entry new_entry(key, V(), hash(key));
        arr[idx].push_back(new_entry);
        sz++;
        return arr[idx].back().value;
    }

    private:
    // Get index for current capacity
    int get_index(int hash_code) {
        return (hash_code % capacity + capacity) % capacity;
    }

    // Getting hash key
    int hash(K key) {
        return std:: hash<K>()(key);
    }

    /**
     * Resizing the hash table if current {@code loadfactor} exceedes the {@code MAX_THREHOLD}
     */
    void resize() {
        int new_capacity = 2 * capacity;
        vector<vector<Entry>> new_arr(new_capacity);

        for(int i = 0; i < capacity; i++) {
            for(int j = 0; j < arr[i].size(); j++) {
                int new_index = get_index(arr[i][j].hash_code % new_capacity);
                new_arr[new_index].push_back(arr[i][j]);
            } 
        }
        arr = new_arr;
        capacity = new_capacity;
    }

};

int main() {
    HashTable<string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);
    cout << ht["one"] << '\n';
    cout << ht["h"] << '\n';
    cout << ht.size() << '\n';
    ht.delKey("one");
    cout << ht.find("one") << " Size: " << ht.size() << '\n';
    ht.delKey("Four");
    return 0;
}
