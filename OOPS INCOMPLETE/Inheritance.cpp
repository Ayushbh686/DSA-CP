#include<iostream>
using namespace std;

class A{
    public:
        int a_ka_public = 1;// can be accessed and inherited 
        A(){
            cout<<"A CONSTRUCTOR CALLED"<<endl;
        }
    protected:
        int a_ka_protected = 2;// can be inherited but can be accessed 
    private:
        int a_ka_private = 3;// cant be inherited and cant be accessed 
};
// while inheriting the security either increases or remain same but cant be decreased;

class B: public A{ //security cant be decreased
    public :
        int b_ka_public = 4;// can be accessed and inherited
        B(){
            cout<<"B CONSTRUCOTR CALLED"<<endl;
        } 
    protected:
        int b_ka_protected = 5;// can be inherited but can be accessed 
    private:
        int b_ka_private = 6;// cant be inherited and cant be accessed 
};

class C:private B{ // security increases
    public:
    C(){
        cout<<"C COSTRUCTOR CALLED"<<endl;
    }
        void showVar(){
            cout<<a_ka_protected<<"\n"<<a_ka_public<<endl;
            cout<<b_ka_protected<<"\n"<<b_ka_public<<endl;
        }
};

int main(){
    A a;
    B b;
    C c;
    cout<<a.a_ka_public<<endl;
    //cout<<b.a_ka_public<<b.b_ka_public<<endl; // these can be accessed
    //cout<<c.a_ka_public<<c.b_ka_public<<endl; // none can be accessed 
    c.showVar();
    return 0;
}