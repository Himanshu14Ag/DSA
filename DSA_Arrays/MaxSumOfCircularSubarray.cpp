#include<iostream>
using namespace std;

//Naive Solution

int maxSumSubarray(int arr[], int n){
    int res = arr[0];
    for(int i=0;i<n;i++){
        int currMax = arr[i];
        int currSum = arr[i];

        for(int j=1;j<n;j++){
            int index = (i+j)%n;
            currSum += arr[index];
            currMax = max(currSum, currMax); 
        }
        res = max(res, currMax);
    }
    return res;
}

// Optimal Solution 

int normalMaxSum(int arr[] , int n){
    int res = arr[0] , maxEnding = arr[0];
    for(int i=1;i<n;i++){
        maxEnding  = max(arr[i] , maxEnding + arr[i]);
        res = max(res , maxEnding);
    }
    return res;
}

int MaxSum(int arr[] , int n){
    int max_Normal = normalMaxSum(arr,n);
    if(max_Normal<0)
        return max_Normal;

    int arr_sum = 0;
    for(int i=0;i<n;i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int maxCircular = arr_sum + normalMaxSum(arr,n);
    return max(max_Normal , maxCircular);
}

//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
int main(){
    int arr[] = {8,-4,3,-5,4};
    int n = 5;
    cout<<"Max sum subarray : "<<maxSumSubarray(arr,n)<<endl;
    cout<<"Max sum subarray : "<<MaxSum(arr,n)<<endl;
}