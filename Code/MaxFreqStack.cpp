#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    map<int, int> freqMap;

    map<int, stack<int> > setMap;

    int maxfreq = 0;

    FreqStack() {

    }

    void push(int val) {
        int freq = freqMap[val] + 1;

        freqMap[val]++;
        if (freqMap[val] > maxfreq) {
            maxfreq = freqMap[val];
        }
        setMap[freq].push(val);

    }

    int pop() {
        int top = setMap[maxfreq].top();
        setMap[maxfreq].pop();
        --freqMap[top];

        if (setMap[maxfreq].empty()) {
            maxfreq--;
        }

        return top;
    }
};

int main() {

    FreqStack* obj = new FreqStack();
    obj->push(val);
    int param_2 = obj->pop();

    return 0;
}

/*

FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
*/