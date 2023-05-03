#include<iostream>
#include<algorithm>
using namespace std;

//Naive Solution -------------------
void merge(int arr[],int arr2[],int n,int m){
    int c[m+n];
    for(int i=0;i<n;i++)
        c[i] = arr[i];
    for(int i=0;i<m;i++)
        c[n+i] = arr2[i];

    sort(c,c+(m+n));
    for(int i=0;i<m+n;i++)
        cout<<c[i]<<" ";
}

//Efficient Solution-----------------
void merges(int arr[],int arr2[],int n,int m){
    int i=0,j=0;
    while(i<n&&j<m){
        if(arr[i]<=arr2[j]){
            cout<<arr[i]<<" ";
            i++;
        }
        else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    while(i<n){
        cout<<arr[i]<<" ";
        i++;
    }
    while(j<m){
        cout<<arr2[j]<<" ";
        j++;
    }
}

int main(){
    int arr[] = {10,15,20};
    int arr2[] = {5,6,6,15};
    int n = 3 , m = 4;
    merge(arr,arr2,n,m);
    cout<<endl;
    merges(arr,arr2,n,m);
}