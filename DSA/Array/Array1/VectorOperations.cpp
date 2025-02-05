#include<iostream>
#include<vector>
#include<algorithm>// for sort
using namespace std;
int main(){
    vector<int>v(5,7);//array of size 5 with each element equal to 7
    v[0]=6;
    v[1]=6;
    v[2]=6;
    v[3]=6;
    v[4]=6;
    cout<<v.size()<<" "<<v[4]<<endl;
    v.pop_back(); //reduces the size 
    cout<<v.size()<<" "<<v[4]<<endl;

    vector<int>A;
    for(int i=0 ; i<=5 ; i++){
        //cin>>v[i]; //wrong when no initial size mentioned as capacity is dorectly zero
        int x;
        cin>>x;
        A.push_back(x);
    }
    for(int i=0; i<=5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    //sort
    sort(A.begin(),A.end());
    for( int i =0; i<=5 ; i++){
        cout<<A[i]<<" ";
    }

    //at function
    for( int i =0; i<=5 ; i++){
        A.at(i)=9;
    }
    cout<<endl;
     for( int i =0; i<=5 ; i++){
        cout<<A[i]<<" ";
    }
    
    return 0;

}
//The issue with your code is that after calling pop_back(), the size of the vector is reduced, but the element at the last index (in this case, v[4]) is not removed or modified. The pop_back() function in C++ is used to remove the last element from the vector, but it does not actually change the value of the element at the last index.