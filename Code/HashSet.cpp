#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    vector<int> v[100];
    const int hf = 100;
    MyHashSet() {

    }

    void add(int key) {
        int id = key % 100;
        if (!contains(key)) {
            v[id].push_back(key);
        }
    }

    void remove(int key) {
        int id = key % 100;
        for (int i = 0; i < v[id].size(); i++) {
            if (v[id][i] == key) {
                v[id].erase(v[id].begin() + i);
                break;
            }
        }
    }

    bool contains(int key) {
        int id = key % 100;
        for (int i = 0; i < v[id].size(); i++) {
            if (v[id][i] == key) {
                return true;
            }
        }
        return false;
    }
};


int main() {

    MyHashSet* obj = new MyHashSet();
    int key = 3;
    obj->add(key);
    obj->remove(key);
    bool param_3 = obj->contains(key);
    return 0;
}

/*

MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

*/