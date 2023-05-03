#include<iostream>
using namespace std;

//Naive solution
int LinearSearch(int arr[], int x, int n){
    for(int i=0;i<n;i++){
        if(arr[i] == x)
            return i;
    }
    return -1;
}

//Efficient solution
int BinarySearch(int arr[], int n , int x){
    int low = 0 , high = n-1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

//Recursive solution
int BinarySearch(int arr[], int n, int low, int high, int x){
    if(low>high)
        return -1;

    int mid = (low+high)/2;

    if(arr[mid]==x)
            return mid;
        else if(arr[mid] < x)
            return BinarySearch(arr,n,mid+1,high,x);
        else
            return BinarySearch(arr,n,low,mid-1,x);
}


//''''''''''''''''''''''''''''''''''''''''''''''''''''''


int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9 , x = 4;
    int low = 0 , high = n-1;

    cout<<"LinearSearch - "<<LinearSearch(arr,x,n)<<endl;
    cout<<"BinarySearch - "<<BinarySearch(arr,n,x)<<endl;
    cout<<"BinaryRecursiveSearch - "<<BinarySearch(arr,n,low,high,x);
}