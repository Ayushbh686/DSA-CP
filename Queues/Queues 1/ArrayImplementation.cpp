#include<iostream>
using namespace std;

class Queue {
public:
    int f = -1, b = -1;
    int arr[6];

    void push(int val) {
        if (b == 5) {
            cout << "Overflow\n";
            return;
        }
        b++;
        arr[b] = val;
        if (f == -1) f++;
    }

    void pop() {
        if (f == -1 || f > b) {
            cout << "Underflow\n";
            return;
        }
        f++;
        if (f > b) { // Reset the queue when it becomes empty
            f = b = -1;
        }
    }

    int size() {
        if (f == -1 || f > b) return 0;
        return b - f + 1;
    }

    bool empty() {
        if (f == -1 || f > b) return true;
        return false;
    }

    int front() {
        if (f == -1 || f > b) {
            cout << "Underflow ";
            return -1000;
        }
        return arr[f];
    }

    int back() {
        if (b == -1 || b < f) {
            cout << "Underflow ";
            return -1000;
        }
        return arr[b];
    }

    void display() {
        if (f == -1 || f > b) {
            cout << "Underflow\n";
            return;
        }
        for (int i = f; i <= b; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Queue q;
    cout<<q.size()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // front(pop) 10 20 30 40 50 back(push) , in stack no front (its closed) only back for pop and push and its top
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    q.display();
    q.push(10); // problem here thats the limitation of array implementation
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    cout<<q.size()<<endl;
    q.push(70);
    q.display();
    return 0;
}