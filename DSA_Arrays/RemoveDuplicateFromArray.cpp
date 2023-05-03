#include<iostream>
using namespace std;

//Naive solution

int removeDist(int arr[], int n){
    int res = 1;
    int temp[n];
    temp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if(temp[res-1]!=arr[i]){
            temp[res] = arr[i];
            res++;  
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    return res;

}

//Efficient Solution

int remDist(int arr[],int n){
    int rest = 1;

    for(int i=1;i<n;i++)
    {
        if(arr[i] != arr[rest-1])
        {
            arr[rest] = arr[i];
            rest++;
        }
    }
    return rest;
}


int main(){
    
    int arr[] = {1,2,2,3,4,5,5,5};
    int n = 8;
    cout<<removeDist(arr,n);
    cout<<endl;
    cout<<remDist(arr,n);
}