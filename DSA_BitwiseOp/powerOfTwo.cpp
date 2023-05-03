
#include<iostream>
using namespace std;

// naive method

int powOfTwo(int n){
    if(n==0)
        return false;
    while(n!= 1){
        if(n%2 != 0)
            return false;
        n = n/2;
    }
    return true;
}

// Efficient Method

int powOfTwo2(int n){
    if(n == 0)
        return false;
    
    return ((n&(n-1)) == 0);
}

int main(){

    int n = 10;
    cout<<powOfTwo(n)<<endl;
    cout<<powOfTwo2(n)<<endl;
    
}