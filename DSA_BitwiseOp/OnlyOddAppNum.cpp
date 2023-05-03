
#include<iostream>
using namespace std;

// Naive Solution
int findOdd(int arr[] , int n){
    for(int i=0;i<n;i++){
    int count = 0;
    for(int j=0;j<n;j++){
        if(arr[j]==arr[i])
            count++;
    }
    if(count%2 != 0)
        cout<<"Odd No : "<<arr[i];
    }
}


// Efficient Solution

int FindOdd(int arr[] , int n){
    int res = 0;
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    return res;
}


// Variation Question

int var(int arr1[] , int n2){
    int res1 = 0 , res2 = 0;
    for(int i=1;i<=n2+1;i++){
        res1 = res1 ^ i;
    }

    for(int i=0;i<n2;i++){
        res2 = res2 ^ arr1[i];
    }

    return res1^res2;
}


int main(){

    int arr[] = {4,3,4,4,4,5,5};
    int n = 7;

    findOdd(arr,n);
    cout<<endl;
    cout<<"Odd No : "<<FindOdd(arr,n);
    cout<<endl;

    int arr1[] = {1,4,5,3};
    int n2 = 4;
    cout<<"Missing: "<<var(arr1,n2);

}