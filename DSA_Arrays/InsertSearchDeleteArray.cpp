#include<iostream>
using namespace std;

int search(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}

int insert(int arr[],int n,int x,int cap,int pos){
    if(n==cap)
        return n;

    int idx = pos - 1 ;
    for(int i=(n-1) ; i>=idx ; i--)
        arr[i+1] = arr[i];

    arr[idx] = x;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" | ";

    return (n+1);
}

int delOp(int arr[],int x,int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==x)
            break;
    }
    if(i==n)
        return n;

    for(int j = i;j<n-1;j++)
        arr[j] = arr[j+1];

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" | ";

    return (n-1); 
}


int main(){

    int arr[] = {12,23,53,54,67,78,89};
    int n = 7;
    int x = 54;

    cout<<search(arr,n,x)<<endl;

    x = 56;
    n = 7; 
    int cap = 8;
    int pos = 3;

    cout<<insert(arr,n,x,cap,pos)<<endl;

    x = 54;
    cout<<delOp(arr,x,n)<<endl;

}