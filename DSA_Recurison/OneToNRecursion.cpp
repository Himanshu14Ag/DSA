#include<iostream>
using namespace std;

// print 1 to n using recursion

void OnetoNRec(int n){
    if(n==0)
        return;
    
    cout<<n<<" ";
    OnetoNRec(n-1);

}

// print n to 1 using recursion

void NtoOneRec(int n){
    if(n==0)
        return;
    
    NtoOneRec(n-1);
    cout<<n<<" ";
}


int main(){

    int n=7;
    cout<<"1ton recursion"<<endl;
    OnetoNRec(n);
    cout<<endl;
    cout<<"nto1 recursion"<<endl;
    NtoOneRec(n);

}
