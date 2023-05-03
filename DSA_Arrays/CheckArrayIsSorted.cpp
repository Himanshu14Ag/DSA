
#include<iostream>
using namespace std;

//Naive method

bool Sorted(int arr[],int n){
    
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[i])
                return false;
        }
    }
    return true;
}

//Efficient method

bool isSorted(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;

}

int main(){
    
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    cout<<Sorted(arr,n);
    cout<<endl;
    cout<<isSorted(arr,n);
}