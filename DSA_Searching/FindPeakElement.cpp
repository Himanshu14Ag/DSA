#include<iostream>
using namespace std;

//Naive solution --------------
int getPeak(int arr[], int n){
    if(n==1)
        return arr[0];
    if(arr[0]>arr[1])
        return arr[0];
    if(arr[n-1]>arr[n-2])
        return arr[n-1];

    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            return arr[i];
    }
}

//Efficient Solution ---------------
int getPeaks(int arr[], int n){
    int low = 0 , high = n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
            return arr[mid];

        if(mid>0 && arr[mid-1]>=arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main(){
    
    int arr[] = {10,20,15,5,23,90,67};
    int n = 7;
    cout<<"Naive solution : "<<getPeak(arr,n)<<endl;
    cout<<"Efficient solution : "<<getPeaks(arr,n);

}