#include<iostream>
using namespace std;

//First Occurance ----------
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

//Last Occurance -------------
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

//Optimal Solution -----------------------------

int CountOcc(int arr[],int x,int n){
    int first = ItrFirstOcc(arr,x,n);
    if(first == -1)
        return 0;
    else
        return (ItrLastOcc(arr,x,n) - first + 1);
}


int main(){
    
    int arr[] = {5,10,10,20,20};
    int n = 5;
    int x = 10;
    cout<<"Count Occurance : "<<CountOcc(arr,x,n)<<endl;
}