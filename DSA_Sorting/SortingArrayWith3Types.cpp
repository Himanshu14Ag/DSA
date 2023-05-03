#include<iostream>
using namespace std;

//Naive Solution -------------------------------
void sort(int arr[],int n){
    int temp[n],i=0;
    for(int j=0;j<n;j++){
        if(arr[j]==0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j]==1){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j]==2){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++)
        arr[j] = temp[j];
}

//Efficint Solution ----------------------------
void Sorting(int arr[],int n){
    int low=0, high=n-1, mid=0;
    while(mid<high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
            mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


int main(){
    int arr[] = {1,0,1,0,2,1,2};
    int n = 7; 
    sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    Sorting(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}