#include<bits/stdc++.h>
using namespace std;

int NextNum(int n){
    int temp = n;
    for(int k=0 ; k<31 ; k++){
        int kBit = (temp>>k) & 1;
        int k1Bit = (temp>>(k+1)) & 1;
        if(kBit == 1 and k1Bit == 0){
            n = n ^ (1<<k);
            n = n ^ (1<<(k+1));

            int oneCount = 0;
            //count one before k
            for(int i = k-1 ; i >= 0 ; i--){
                if((temp>>i) & 1) oneCount++;
            }
            // cout<<k<<" "<<oneCount<<endl;

            //make oneCOunt number of one 
            for(int i=0 ; i<oneCount ; i++){
                n = n | (1<<i);
            }
            // cout<<n<<endl;
            
            //make remaining zeros
            for(int i = oneCount ; i<k ; i++){
                n = n & ~(1<<i);
            }

            return n;
        }
    }
    return n;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        //current number 
        int n;
        cin>>n;

        //next number with same ones as in this n
        cout<<NextNum(n)<<endl;
    }
    return 0;
}