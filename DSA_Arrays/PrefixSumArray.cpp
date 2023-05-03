#include<iostream>
using namespace std;

// build a prefix sum array ---------
int prefixSum(int arr[], int n, int left, int right){
    int pfsum[n];
    pfsum[0] = arr[0];
    for(int i=0;i<n;i++)
        pfsum[i] = pfsum[i-1] + arr[i];

    if(left != 0)
        return (pfsum[right] - pfsum[left-1]);
    else
        return (pfsum[right]);
}


// Find the Equilibrium point in a given array ----------
bool isEquiPoint(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum = sum + arr[i];

    int lsum = 0 ;
    for(int i=0;i<n;i++){
        if(lsum == (sum-arr[i]))
            return true;
        
        lsum += arr[i];
        sum -= arr[i];  
    }
    return false;
}


int main(){
    int arr[] = {2,8,3,9,6,5,4};
    int n = 7;
    int left = 2 , right = 6;
    cout<<"Prefix Sum : "<<prefixSum(arr,n,left,right)<<endl;

    int sarr[] = {3,4,8,-9,20,6};
    int num = 6;
    if(1 == isEquiPoint(sarr,num))
        cout<<"Equilibrium : yes"<<endl;
    else
        cout<<"Equilibrium : no"<<endl;
}