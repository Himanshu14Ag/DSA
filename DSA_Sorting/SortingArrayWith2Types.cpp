#include<iostream>
using namespace std;

// Naive Solution -------------------------------
void Segregate(int arr[],int n){
    int temp[n], i = 0;
    for(int j=0;j<n;j++){
        if(arr[j]<0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j]>=0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        arr[j] = temp[j];
    }
}

// Efficient Solution -------------------------------
void SegregatePosNeg(int arr[],int n){
    int i=-1,j=n;
    while(true){
        do{
            i++;
        }while(arr[i]<0);
        do{
            j--;
        }while(arr[j]>=0);

        if(i>=j)
            return;
        
        swap(arr[i],arr[j]);
    }
}


int main(){
    int arr[] = {15,-3,-2,18};
    int n = 4;
    Segregate(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    SegregatePosNeg(arr,n);
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}