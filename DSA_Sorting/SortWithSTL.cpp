#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    int arr[] = {20,5,7,10};
    int n=4;
    sort(arr,arr+n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;

    vector<int> v = {7,5,20,10};
    sort(v.begin(),v.end());
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
}