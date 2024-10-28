#include<iostream>
#include<vector>
using namespace std;

vector<long long int> factorial(int n){
    vector<long long int> fact(n+1, 1);
    int k = 1000000000 + 7;
    for(int i = 2; i <= n; i++){  // Corrected loop condition
        fact[i] = ((fact[i-1] % k) * (i % k)) % k;
    }
    return fact;
}

int main(){
    vector<long long int> res = factorial(25);  // Corrected vector type
    for(int i = 0; i <= res.size() ; i++) cout << i << "! = " << res[i] << endl;  // Corrected loop condition
    return 0;
}
