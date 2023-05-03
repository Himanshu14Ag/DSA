#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BucketSort(int arr[],int n,int k){
    int maxval = arr[0];
    for(int i=1;i<n;i++)
        maxval = max(maxval,arr[i]);
    
    maxval++;

    vector<int> bkt[k];
    for(int i=0;i<n;i++){
        int bi = (k*arr[i])/maxval;
        bkt[bi].push_back(arr[i]);
    }

    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());

    int index = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++)
            arr[index++] = bkt[i][j];
    }
}

int main(){
    int arr[] = {20,88,70,85,75,95,18,82,16};
    int n = 9,k = 5;
    BucketSort(arr,n,k);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}