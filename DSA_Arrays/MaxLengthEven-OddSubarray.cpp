#include<iostream>
using namespace std;

//Naive solution
int MaxEvenOdd(int arr[] , int n){
    int res = 1;
    for(int i=0;i<n;i++){
        int curr = 1;
        for(int j=i+1;j<n;j++){
            if(arr[j]%2==0 && arr[j-1]%2!=0 || arr[j]%2!=0 && arr[j-1]%2==0)
                curr++;
            else
                break;
        }
        res = max(res,curr);
    }
    return res;
}

//Efficient Solution
int MaxEvenOddNum(int arr[] , int n){
    int res = 1;
    int curr = 1;
    for(int i=1;i<n;i++){
        if(arr[i]%2==0 && arr[i-1]%2!=0 || arr[i]%2!=0 && arr[i-1]%2==0){
            curr++;
            res = max(res,curr);
        }
        else
            curr = 1;
        }
    return res;
}

int main(){
    int arr[] = {5,20,10,6,3,8};
    int n = 6;
    cout<<"Ans - "<<MaxEvenOdd(arr,n)<<endl;
    cout<<"Ans - "<<MaxEvenOddNum(arr,n)<<endl;
}