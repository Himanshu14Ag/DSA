
#include<iostream>
using namespace std;

//Simple -----------
void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

//Optimised ----------
void Bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }    
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {2,10,8,7};
    int n = 4;
    BubbleSort(arr,n);
    cout<<endl;
    Bubble(arr,n);
}