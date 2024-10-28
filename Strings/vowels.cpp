#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string str;
    cout<<"enter the string : ";
    //char str[n];
    //getline(cin,str);
    getline(cin,str);
    //cin>>str;
    cout<<(int)str[n]<<endl;
    int count=0;
    int i;
    for( i=0 ; i<=(str.length()+1) ; i++){
        if(str[i] =='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' )
         count++;
        if(str[0]=='\0') cout<<i<<endl;
    }
    cout<<count;
}
//not working getline
//In C++, the cin.ignore() function is essential for resolving input-related problems, especially when using the cin and getline functions together. By clearing the input buffer and removing unnecessary characters, developers may ensure input processes behave as expected and accurately