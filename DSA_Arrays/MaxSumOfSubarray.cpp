#include<iostream>
using namespace std;

//Naive Solution
int MaxSum(int arr[],int n){
    int res = arr[0];
    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            curr = curr + arr[j];
            res = max(curr,res);
        }
    }
    return res;
}

//Efficient Solution
int MaxSumSubarray(int arr[],int n){
    int res = arr[0] , maxEnding = arr[0];
    for(int i=0;i<n;i++){
        maxEnding = max(maxEnding + arr[i] , arr[i]);
        res = max(maxEnding,res);
    }
    return res;
}

int main(){
    
    int arr[] = {-3,8,-2,4,-5,6};
    cout<<"Ans = "<<MaxSum(arr,6)<<endl;
    cout<<"Ans = "<<MaxSumSubarray(arr,6)<<endl;

}