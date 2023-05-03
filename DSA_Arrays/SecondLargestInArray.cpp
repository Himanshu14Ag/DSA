#include<iostream>
using namespace std;

// naive approach

int getLarge(int arr[], int n){
    int largest=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[largest])
            largest = i;
    }
    return largest;
}

int getSecondLargest(int arr[], int n){
    int largest = getLarge(arr,n);
    int res = -1;

    for(int i=0;i<n;i++){
        if(arr[i] != arr[largest])
        {
            if(res == -1)
                res = i;
            
            else if(arr[i]>arr[res])
                res = i;
        }
    }
    return res;
}

// Efficient Approach

int SecondLargest(int arr[] , int n){
    int res = -1 , largest = 0;

    for(int i=0;i<n;i++){
        if(arr[i]>arr[largest]){
            res = largest;
            largest = i;
        }
        else if(arr[i] != arr[largest]){
            if(res == -1 || arr[i]>arr[res])
                res = i;
        }
    }
    return res;
}


int main(){
    
    int arr[] = {11,34,21,54,13,54};
    int n = 6;
    cout<<getSecondLargest(arr,n)<<endl;
    cout<<SecondLargest(arr,n);

}