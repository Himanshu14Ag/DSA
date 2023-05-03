
#include<iostream>
#include<limits.h>
using namespace std;

//Naive Solution -------------------
int sum(int arr[],int b,int e){
    int s=0;
    for(int i=b;i<e;i++)
        s += arr[i];
    
    return s;
}

int minPages(int arr[],int n,int k){
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    
    int res = INT_MAX;

    for(int i=0;i<n;i++){
        res = min(res, max(minPages(arr,i,k-1), sum(arr,i,n-1)));
    }
    return res;
}


// Efficient Solution --------------------------
bool isFlexible(int arr[],int n,int k,int ans){
    int req=1, sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i] > ans){
            req++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (req <= k);
}


int minNumPages(int arr[],int n,int k){
    int sum=0, maxm=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxm = max(maxm , arr[i]);
    }

    int low = maxm, high = sum, res = 0;

    while(low<=high){
        int mid = (low+high)/2;

        if(isFlexible(arr,n,k,mid)){
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return res;
}


// Main function -----------------------------------
int main(){
    int arr[] = {10,20,30,40};
    int n = 4;
    int k = 2;
    cout<<"Min Pages Naive : "<<minPages(arr,n,k)<<endl;
    int arr2[] = {10,5,4,20};
    cout<<"Min Pages Efficient : "<<minNumPages(arr2,n,k);
}