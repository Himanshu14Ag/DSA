
#include<iostream>
using namespace std;

void fun(int n , int k){
    if(n==0)
        return;
    
    cout<<k;
    fun(n-1 , k+1);
} 

int fact(int n , int k){
    if(n==0 || n==1)
        return k;

    return fact(n-1 , n*k);
}

int main(){

    int n = 5 , k = 1;
    fun(n,k);

    cout<<"\n\n\n"<<fact(n,k);

}