#include<iostream>
using namespace std;

//Naive solution ----------------------
void Leader(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i+1; j<n; j++)
        {
            if(arr[i]<=arr[j]){
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout<<arr[i];
        }
    }
    
}

//Efficient Solution---------------------
void Lead(int arr[],int n){
    int currLead = arr[n-1];
    cout<<currLead;

    for(int i = n-2 ; i>=0 ; i--){
        if(currLead<arr[i]){
            currLead = arr[i];
            cout<<currLead;
        }
    }
}

int main(){
    
    int arr[] = {2,3,5,7,4,1};
    int n = 6;
    Leader(arr,n);
    cout<<endl;
    Lead(arr,n);

}