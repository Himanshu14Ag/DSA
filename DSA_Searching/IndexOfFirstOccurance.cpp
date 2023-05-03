#include<iostream>
using namespace std;

//Naive solution ---------

int FirstOcc(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}

//Recursive Solution ------------

int RecFirstOcc(int arr[], int low, int high, int x){
    if(low>high)
        return -1;
    
    int mid = (low + high)/2;
    
    if(x>arr[mid])
        return RecFirstOcc(arr,mid+1,high,x);
    else if(x<arr[mid])
        return RecFirstOcc(arr,low,mid-1,x);
    else{
            if(mid == 0 || arr[mid-1] != arr[mid])
                return mid;
            else
                return RecFirstOcc(arr,low,mid-1,x);
        }
}

//Iterative solution ----------

int ItrFirstOcc(int arr[], int x, int n){
    int low = 0 , high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid]<x)
            low = mid+1;
        else if(arr[mid]>x)
            high = mid-1;
        else{
            if(mid==0 || arr[mid-1] != arr[mid])
                return mid;
            else
                return
                    high = mid-1;
        }
    }
    return -1;
}

int main(){
    
    int arr[] = {5,10,10,20,20};
    int n = 5;
    int x = 10;
    int low = 0, high = 4;
    cout<<"Naive : "<<FirstOcc(arr,n,x)<<endl;
    cout<<"Recursive : "<<RecFirstOcc(arr,low,high,x)<<endl;
    cout<<"Iterative : "<<ItrFirstOcc(arr,x,n)<<endl;
}