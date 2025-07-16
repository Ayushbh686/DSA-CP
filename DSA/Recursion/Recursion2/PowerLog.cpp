// #include<iostream>
// using namespace std;
// int pow(int a,int b){
//     if(b==0) return 1;
//     int ans = pow(a,b/2);
//     if(b%2==1) return ans*ans*a;
//     return ans*ans;
// }
// int main(){
//     int a,b;
//     cout<<"enter the base and exponent : ";
//     cin>>a>>b;
//     cout<<pow(a,b);
//     return 0;
// }

//iterative solution
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
            } else {
            x = x * x;
            nn = nn / 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};