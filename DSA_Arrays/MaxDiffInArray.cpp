#include<iostream>
using namespace std;

//Navie Solution------------
int MaxDiff(int n , int arr[]){
    int res = arr[1] - arr[0];
    
    for(int i=0;i<n-1;i++){
        for(int j = i+1; j<n; j++){
            res = max(res , arr[j]-arr[i]);
        }
    }
    
    return res;
}

//Efficient Solution------------
int MaximaDiff(int arr[] , int n){
    int res = arr[1] - arr[0];
    int minVal = arr[0];

    for(int i=1;i<n;i++){
        res = max(res, arr[i]-minVal);
        minVal = min(minVal,arr[i]);
    }

    return res;
}

int main(){
    
    int arr[] = {2,4,6,8,3,1};
    int n = 6;
    cout<<MaxDiff(n,arr);
    cout<<endl;
    cout<<MaximaDiff(arr,n);
}