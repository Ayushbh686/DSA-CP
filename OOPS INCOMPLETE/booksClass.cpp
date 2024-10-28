#include<iostream>
using namespace std;

class book{
    private:
        int price;
        string name ;
        int length;

    public:
        void setPrice(int p){
            this->price = p;   // this is a pointer so (*this).price = p; is valid  
        }

        void setName(string s){
            book::name = s;
        }

        void setLength(int l){
            book::length = l; // alternative is this.length = length when both keywords same
        }

        bool isPrice(int p){
            return p > price;
        }

        bool isPresent(string n){
            return n == name;
        }
        
};

int main(){
    book Metamorphosis;
    Metamorphosis.setName("Mpr");
    Metamorphosis.setLength(180);
    Metamorphosis.setPrice(400);
    cout<<(bool)Metamorphosis.isPrice(410)<<endl;
    cout<<(bool)Metamorphosis.isPresent("Mpr")<<endl;
    return 0;
}
// Preferably data members should be private and its methods should be public and data members must be initialised thtough getters and setters(public)