#include<bits/stdc++.h>
using namespace std;

// Naive Solution -------------------
void PrintFreq(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = true;
                break;
            }
        }
        if(flag == true)
            continue;

        int freq = 1;

        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                freq++;
        }
        cout<<arr[i]<<" "<<freq<<endl;
    }
}

// Efficient Solution ------------------
int countFreq(int arr[],int n){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto x : m)
        cout<<x.first<<" "<<x.second<<endl;
}

int main(){
    int arr[] = {10,20,30,10,20,10};
    int n = 6;
    PrintFreq(arr,n);
    cout<<endl;
    cout<<endl;
    countFreq(arr,n);
}