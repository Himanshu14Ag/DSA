#include<bits/stdc++.h>
using namespace std;

// naive Solution ---------
int countDist(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            res++;
    }
    return res;
}

// Efficient Solution -----------
int CountDist(int arr[],int n){
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    
    return s.size();
}


int main(){
    int arr[] = {10,20,30,10,20};
    int n = 5;
    cout<<countDist(arr,n)<<endl;
    cout<<CountDist(arr,n);
}