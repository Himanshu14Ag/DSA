#include<iostream>
using namespace std;

void Partition(int arr[],int low,int high,int p){
    int temp[high-low+1] , index = 0;

    for(int i=low;i<=high;i++){
        if(arr[i]<=arr[p]){
            temp[index] = arr[i];
            index++;
        }
    }
    for(int i=low;i<=high;i++){
        if(arr[i]>arr[p]){
            temp[index] = arr[i];
            index++;
        }
    }
    for(int i=low;i<=high;i++)
        arr[i] = temp[i-low];

    for(int i=0;i<=high;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {5,13,6,9,12,11,8};
    int low = 0, high = 6, p=6;
    Partition(arr,low,high,p);

}