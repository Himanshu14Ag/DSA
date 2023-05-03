
#include<iostream>
using namespace std;

// Naive solution

int countSet(int n){
    int res = 0;
    while(n>0){
        if((n&1)==1)
            res++;
        n = n>>1;
    }
    return res;
}

// Brian Kerningam Algorithm

int countSet2(int n){
    int res = 0;
    while(n>0){
        n = (n&(n-1));
        res++;
    }
    return res;
}

// Lookup Table Method

int table[256];

void initialize(){
    table[0] = 0;

    for(int i = 1; i < 256 ; i++){
        table[i] = (i&1) + table[i/2];
    }
}

int countSet3(int n){

    int res = table[n & 0xff];
    n = n>>8;

    res = res + table[n & 0xff];
    n = n>>8;

    res = res + table[n & 0xff];
    n = n>>8;

    res = res + table[n & 0xff];
    return res;
}




int main()
{
    int n = 40;
    cout<<countSet(n)<<endl;
    cout<<countSet2(n)<<endl;
    initialize();
    cout<<countSet3(n)<<endl;
}
