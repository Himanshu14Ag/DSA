
#include<iostream>
using namespace std;

void reverse(int arr[],int n){
    int low=0 , high=n-1;
    while(low < high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    int arr[] = {1,3,4,6,7,8,9};
    int n = 7;
    reverse(arr,n);

}