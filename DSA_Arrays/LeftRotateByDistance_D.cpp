#include<iostream>
using namespace std;

// Naive Solution

void LeftRotate(int arr[],int n){
    int temp = arr[0];
    for (int i = 0; i < n; i++)
        arr[i-1] = arr[i];
    
    arr[n-1] = temp;

}

void LeftRotateByD(int arr[],int n,int d){
    for (int i = 0; i < d; i++)
        LeftRotate(arr,n);
    
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    
}

// Efficient Solution

void LeftRotated(int arr[],int d,int n){
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];
    
    for (int i = d; i < n; i++)
        arr[i-d] = arr[i];

    for (int i = 0; i < d; i++)
        arr[n-d+i] = temp[i];

}

// Most Efficient Solution

void reverseArr(int arr[],int high,int low){
    while (low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    
}

void RotateLeft(int arr[],int n,int d){
    reverseArr(arr,0,d-1);
    reverseArr(arr,d,n-1);
    reverseArr(arr,0,n-1);

    
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int d = 3;

    LeftRotateByD(arr,n,d);
    cout<<endl;
    LeftRotated(arr,d,n);
    cout<<endl;
    RotateLeft(arr,n,d);
    
}
