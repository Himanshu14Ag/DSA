
#include<iostream>
#include<limits.h>
using namespace std;

// Naive ---------------------
void SelectionSort(int arr[],int n){
    int temp[n];
    for(int i=0;i<n;i++){
        int min_idx = 0;
        for(int j=1;j<n;j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        temp[i] = arr[min_idx];
        arr[min_idx] = INT_MAX;
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
        cout<<arr[i]<<" ";
    }
}

//Optimal -------------------------
void SelectSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        swap(arr[min_idx],arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {10,5,8,20,2,18};
    int n = 6;
    SelectionSort(arr,n);
    cout<<endl;
    SelectSort(arr,n);
}