#include<iostream>
using namespace std;
// Find the two odd Appearing numbers

void TwoOdd(int arr[] , int n){
    int res1 = 0 , res2 = 0 , Xor = 0;

    for(int i=0 ; i<n ; i++){
        Xor = Xor ^ arr[i];
    }

    int sb = Xor & ~(Xor-1);

    for(int i=0 ; i<n ; i++){
        if((arr[i]&sb) != 0)
            res1 = res1 ^ arr[i];
        
        else
            res2 = res2 ^ arr[i];
    }

    cout<<res1<<" "<<res2;

}

int main(){
    int arr[] = {3,4,3,4,5,4,4,6,7,7};
    int n = 10;

    TwoOdd(arr,n);
}