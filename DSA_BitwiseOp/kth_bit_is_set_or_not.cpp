
#include<iostream>
using namespace std;


// left shift method

void kth_bit(int n , int k){

    if(n & (1 << (k-1)) != 0) 
        cout<<"Yes";
    
    else
        cout<<"No";

}


// Right shift method

void kth_bit2(int n , int k){

    if((n >> (k-1)) & 1 == 1)
        cout<<"Yes";
    
    else
        cout<<"No";

}

int main(){

    int n = 5,k = 3;
    kth_bit(n,k);
    n = 13 ;
    k = 3; 
    cout<<endl;
    kth_bit2(n,k);
}

