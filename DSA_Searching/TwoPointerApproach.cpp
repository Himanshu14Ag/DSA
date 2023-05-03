#include<iostream>
using namespace std;

//For finding a pair of element ------------ 
bool isPair(int arr[], int left, int right, int x){

    while(left<right){
        
        if(arr[left]+arr[right] == x)
            return true;
        else if(arr[left]+arr[right]>x)
            right--;
        else
            left++;
    }
    return false;
}

//Finding a Pair of triplet element ------------
bool isTripletPair(int arr[],int x,int n){
    for(int i=0;i<n;i++){
        if(isPair(arr, i+1, n-1, x-arr[i]))
            return true;
    }
    return false;
}

int main(){
    
    int arr[] = {2,3,4,8,9,20,40};
    int x = 28, n = 7, left = 0;
    int right = n-1;

    if(isPair(arr,left,right,x) == 1)
        cout<<"Two Pairs : Yes"<<endl;
    else
        cout<<"Two Pairs : No"<<endl;
    
    int x2 = 32;

     if(isTripletPair(arr,x2,n) == 1)
        cout<<"Three Pairs : Yes"<<endl;
    else
        cout<<"Three Pairs : No"<<endl;

}