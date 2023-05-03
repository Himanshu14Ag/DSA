
#include<iostream>
using namespace std;

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

    for(int i=0;i<=high;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {10,80,30,90,40,50,70};
    int low = 0, high = 6;
    LomutoPartition(arr,low,high);
}