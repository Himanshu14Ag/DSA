#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1 , n2 = high-mid;
    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[low+i];
    for(int i=0;i<n2;i++)
        right[i] = arr[n1+i];

    int i=0,j=0,k=0;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }

    for(int i=0;i<=high;i++)
        cout<<arr[i]<<" ";
}


int main(){
    int arr[] = {10,15,20,11,30};
    int low = 0,high = 4, mid = 2;
    merge(arr,low,mid,high);
}