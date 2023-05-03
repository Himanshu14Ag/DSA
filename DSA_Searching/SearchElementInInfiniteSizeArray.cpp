
#include<iostream>
using namespace std;

//Naive Solution -------------
int Search (int arr[],int x){
    int i=0;
    while(true){
        if(arr[i]==x)
            return i;
        if(arr[i]>x)
            return -1;
        i++;
    }
}

//Binary Search -------------------
int BinarySearch(int arr[],int low, int high, int x){
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


//Optimal Solution ----------------
int Searches(int arr[], int x){
    if(arr[0]==x)
        return 0;

    int i = 1;
    while(arr[i]<x)
        i = i*2;
    
    if(arr[i]==x)
    return i;

    return BinarySearch(arr,i/2+1,i-1,x);
}


int main(){
    int arr[] = {1,2,4,5,7,12,13,14,16,17,21,24,43,56,58,76,79,100,211};
    int n = 17;
    cout<<"Naive Search : "<<Search(arr,n)<<endl;
    cout<<"Optimised Search : "<<Searches(arr,n);
    
}