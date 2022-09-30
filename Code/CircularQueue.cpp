#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {

public:
   vector<int> q;
   int front = 0, rear = 0, size = 0;

   MyCircularQueue(int k) {
      q.resize(k, -1);
   }

   bool enQueue(int value) {
      if (isFull()) {
         return false;
      }
      if (isEmpty()) {
         front = rear = 0;
         q[rear] = value;
         size++;
         return true;
      }

      rear++;
      size++;
      rear = rear % q.size();
      q[rear] = value;
      return true;
   }

   bool deQueue() {
      if (isEmpty()) {
         return false;
      }
      q[front] = -1;
      size--;
      front++;
      front = front % q.size();
      return true;
   }

   int Front() {
      return q[front];
   }

   int Rear() {
      return q[rear];
   }

   bool isEmpty() {
      return size == 0;
   }

   bool isFull() {
      return size == q.size();
   }
};

int main() {

   int k = 3, value = 2;
   MyCircularQueue* obj = new MyCircularQueue(k);
   bool param_1 = obj->enQueue(value);
   int param_3 = obj->Front();
   int param_4 = obj->Rear();
   bool param_5 = obj->isEmpty();
   bool param_6 = obj->isFull();
   bool param_2 = obj->deQueue();

   return 0;
}

/*

MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4

*/