#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    int BUCKET; //size of a table
    vector<list<pair<int, int>>>table;

    //initialize a size of a table
    MyHashMap() {
        BUCKET = 1000;
        table.resize(BUCKET);
    }

    //hash function
    int hash(int key) {
        return key % BUCKET;
    }

    //iterator function which will return the pointer of a specfic key
    list<pair<int, int>> :: iterator  search(int key) {
        int i = hash(key);
        list<pair<int, int>>:: iterator  itr = table[i].begin();
        while (itr != table[i].end()) {
            if (itr->first == key) {
                return itr;
            }
            itr++;
        }
        return itr;
    }

    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        table[i].push_back({key, value});
    }

    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> ::iterator itr = search(key);
        if (itr == table[i].end()) {
            return -1;
        } else {
            return itr->second;
        }
    }

    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>>:: iterator itr = search(key);
        if (itr != table[i].end()) {
            table[i].erase(itr);
        }
    }
};

int main() {


    MyHashMap* obj = new MyHashMap();
    int key = 1, value = 2;
    obj->put(key, value);
    int param_2 = obj->get(key);
    obj->remove(key);
    return 0;
}

/*

MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

*/