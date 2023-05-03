#include<iostream>
using namespace std;

//naive approach

int getLargest(int arr[] , int n){

    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n;j++){
            if(arr[j] > arr[i]){
                flag = false;
                break;
            }
        }
        if(flag == true)
            return i;
    }

    return -1;
}

//Efficient Approach

int getLarge(int arr[], int n){
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[res])
            res = i;
    }
    return res;
}


int main(){
    int arr[] = {12,43,53,34};
    int n = 4;
    cout<<getLargest(arr,n)<<endl;
    cout<<getLarge(arr,n);
}