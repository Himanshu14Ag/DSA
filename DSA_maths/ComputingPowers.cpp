
#include<iostream>
using namespace std;

//Naive solution

int Power(int x , int n){
    int res = 1; 
    for (int i=0;i<n;i++)
        res = res*x;

    return res; 
}

// Efficient Solution

int Power2(int x, int n){
    if(n==0)
        return 1;
    
    int temp = Power2(x,n/2);
    temp = temp*temp;

    if(n%2==0)
        return temp;

    else
        return temp*x;
}

//Optimal Soution

int Power3(int x, int n){
    int res = 1;
    while(n>0){
        if(n%2!=0)
            res = res*x;
        
        x = x*x;
        n = n/2;
    }  
    return res;
}


int main(){

    int x,n;
    cin>>x>>n;

    cout<<Power(x,n);
    cout<<"\n\n";
    cout<<Power2(x,n);
    cout<<"\n\n";
    cout<<Power3(x,n);
    cout<<"\n\n";
}

