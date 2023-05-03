
#include<iostream>
using namespace std;

int HoarePartition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low-1, j = high+1;
    
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i>=j){
            for(int i=0;i<=high;i++)
                cout<<arr[i]<<" ";

            return j;
        }
        swap(arr[i],arr[j]);
    }
}

int main(){
    int arr[] = {5,3,8,4,2,7,1,10};
    int low = 0, high = 7;
    HoarePartition(arr,low,high);
}