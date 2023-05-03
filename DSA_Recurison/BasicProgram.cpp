
#include<iostream>
using namespace std;

void fun(int n){
    if (n==0)
        return;
    
    cout<<"GFG"<<endl;
    fun(n-1);
}

int main(){
    int n = 3;
    fun(3);
}
