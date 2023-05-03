#include<iostream>
using namespace std;

//Naive ---------------------
int Inverse(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                res++;
        }
    }
    return res;
}

//Efficient --------------------
int CountAndMerge(int arr[],int l,int m,int r){
    int n1 = m-l+1 , n2 = r-m;
    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
        left[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        right[i] = arr[m+1+i];

    int i=0,j=0,k=l,res=0;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
            res += (n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int CountInversion(int arr[],int l,int r){
    int res=0;
    if(l<r){
        int m = l + (r-l)/2;
        res += CountInversion(arr,l,m);
        res += CountInversion(arr,m+1,r);
        res += CountAndMerge(arr,l,m,r);
    }
    return res;
}

int main(){
    int arr[] = {2,5,8,11,3,6,9,13};
    int l=0 , r=7, n=8;
    cout<<Inverse(arr,n)<<endl;
    cout<<CountInversion(arr,l,r);
}