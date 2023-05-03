#include<bits/stdc++.h>
using namespace std;


void printSub(int idx,vector<int>& ds,int arr[],int n,int sum,int s){
    if(idx>=n){
        if(s==sum){
            for(auto it : ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
        return;
    }
    ds.push_back(arr[idx]);
    s += arr[idx];
    printSub(idx+1,ds,arr,n,sum,s);
    
    s -= arr[idx];
    ds.pop_back();
    printSub(idx+1,ds,arr,n,sum,s);
}


int main(){
    int arr[] = {1,2,1};
    int n=3;
    int sum = 2; 
    vector<int> ds;
    printSub(0,ds,arr,n,sum,0);
}