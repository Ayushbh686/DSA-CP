#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
public:
    int f;
    int b;
    int s;
    vector<int> v;
    MyCircularQueue(int k) {
        f = -1;
        b = -1;
        s = 0;
        this->v = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(s == v.size()) return false;
        if(b == v.size() - 1) b = 0;
        else b++;
        v[b] = value;
        s++;
        if(f==-1) f++;
        return true;
    }
    
    bool deQueue() {
        if(s==0) return false;
        if(f == v.size() - 1) f = 0;
        else f++;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return v[f];
    }
    
    int Rear() {
        if(s==0) return -1;
        return v[b];
    }
    
    bool isEmpty() {
        if (s==0) return true;
        return false;
    }
    
    bool isFull() {
        if(s==v.size()) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(){
    
}