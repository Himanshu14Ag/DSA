#include<iostream>
#include<algorithm>
using namespace std;

//Naive Solution -----------------------------

int KthElement(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}

//Optimised solution ---------------

int LomutoPartition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}


int Smallest(int arr[],int n,int k){
    int l=0,r=n-1;
    while(l<=r){
        int p = LomutoPartition(arr,l,r);
        if(p==(k-1))
            return arr[k-1];
        else if(p>(k-1))
            r=p-1;
        else
            l=p+1;
    }
    return -1;
}


int main(){
    int arr[] = {10,4,5,8,11,6,28};
    int l=0,n=7,k=4;
    cout<<"Naive Solution -> "<<KthElement(arr,n,k)<<endl;
    cout<<"Optimised Solution -> "<<Smallest(arr,n,k)<<endl;
}