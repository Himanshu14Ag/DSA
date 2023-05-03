#include<iostream>
using namespace std;

//----- Find the max sum of K consecutive elements --------------

// Naive solution 
int MaxSum(int arr[], int k, int n){
    int maxSum = arr[0];
    for(int i=0;i+k-1<n;i++){
        int sum = 0;
        for(int j=0;j<k;j++)
            sum += arr[i+j];

        maxSum = max(sum, maxSum);
    }  
    return maxSum;
}

//Efficient Solution
int MaxSums(int arr[], int n, int k){
    int currSum = 0;
    for(int i=0; i<k; i++)
        currSum += arr[i];
    
    int maxSum = currSum;
    
    for(int i=k;i<n;i++){
        currSum += (arr[i] -arr[i-k]);
        maxSum = max(maxSum , currSum); 
    }
    return maxSum;
}


//-------------- Finding if there is a subarray with given sum in a non-negative integer array --------------

bool SubSum(int sumArr[] , int n ,int sum){
    int currSum = sumArr[0], start = 0;
    for(int end = 1; end<n; end++){
        while(currSum>sum && start<end-1){
            currSum -= sumArr[start];
            start++;
        }
        if(currSum == sum){
            return true;
        }
        if(end<n){
            currSum += sumArr[end];
        }
    } 
    return (currSum == sum);
}



//--------------------------------------------------------------------

int main(){
    int arr[] = {1,8,30,-5,20,7};
    int n = 6 , k = 3;
    cout<<"Max Sum : "<<MaxSum(arr,k,n)<<endl;
    cout<<"Max Sum : "<<MaxSums(arr,n,k)<<endl;

    int sumArr[] = {1,4,3,61,91,44,27};
    int num = 7, sum = 22;
    int res = SubSum(sumArr, num, sum);
    if(res==1)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    int sumArr2[] = {1,4,6,9,7,20,41};
    int res2 = SubSum(sumArr2, num, sum);
    if(res2==1)
        cout<<"yes";
    else
        cout<<"no";
    
}