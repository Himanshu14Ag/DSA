#include<iostream>
using namespace std;

//Naive solution ---------

int LastOcc(int arr[], int n, int x){
    for(int i=n-1;i>=0;i--){
        if(arr[i]==x)
            return i;
    }
    return -1;
}

//Recursive Solution ------------

int RecLastOcc(int arr[], int low, int high, int x){
    if(low>high)
        return -1;
    
    int mid = (low + high)/2;
    
    if(x>arr[mid])
        return RecLastOcc(arr,mid+1,high,x);
    else if(x<arr[mid])
        return RecLastOcc(arr,low,mid-1,x);
    else{
            if(mid == 0 || arr[mid+1] != arr[mid])
                return mid;
            else
                return RecLastOcc(arr,mid+1,high,x);
        }
}

//Iterative solution ----------

int ItrLastOcc(int arr[], int x, int n){
    int low = 0 , high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid]<x)
            low = mid+1;
        else if(arr[mid]>x)
            high = mid-1;
        else{
            if(mid==0 || arr[mid+1] != arr[mid])
                return mid;
            else
                return
                    low = mid+1;
        }
    }
    return -1;
}

int main(){
    
    int arr[] = {5,10,10,20,20};
    int n = 5;
    int x = 10;
    int low = 0, high = 4;
    cout<<"Naive : "<<LastOcc(arr,n,x)<<endl;
    cout<<"Recursive : "<<RecLastOcc(arr,low,high,x)<<endl;
    cout<<"Iterative : "<<ItrLastOcc(arr,x,n)<<endl;
}