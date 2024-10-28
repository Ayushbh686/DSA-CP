#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> v = {3 , 4 , 11 , 9 , 14 , -1 , 30 , 44 , 50};
    int arr[] = {3 , 4 , 11 , 9 , 14 , -1 , 30 , 44 , 50};
    //priority_queue<int> hp; //maxheap BY defualt // vector , less default parameter
    priority_queue<int , vector<int> , greater<int>>hp;
    priority_queue<int , vector<int> , greater<int>>minHeapVector(v.begin() , v.end());
    priority_queue<int , vector<int> , greater<int> >minHeapArray(arr , arr+9);
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    cout<<hp.top()<<endl;
    cout<<minHeapVector.top()<<endl;
    cout<<minHeapArray.top()<<endl;
}
//priority queue is implemented by heap internally
