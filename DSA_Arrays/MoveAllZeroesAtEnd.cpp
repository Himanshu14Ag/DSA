
#include<iostream>
using namespace std;

//Naive Solution

void MoveAtEnd(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            for(int j=i+1;j<n;j++){
                if(arr[j]!=0)
                    swap(arr[i],arr[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

//Efficient Solution

void MoveToEnd(int arr[],int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0){
            swap(arr[i],arr[count]);
            count++;
        }
    }  

    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}


int main(){
    
    int arr[] = {8,5,0,10,0,20};
    int n = 6;
    MoveAtEnd(arr,n);
    cout<<endl;
    MoveToEnd(arr,n);
}