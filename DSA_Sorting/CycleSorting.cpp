#include<iostream>
using namespace std;

void CycleSort(int arr[],int n){
    for(int cs=0;cs<n-1;cs++){
        int item = arr[cs];
        int pos = cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i] < item)
                pos++;
        }
        swap(item,arr[pos]);
        while(pos!=cs){
            pos = cs;
            for(int i = cs+1;i<n;i++){
                if(arr[i]<item)
                    pos++;
            }
            swap(item,arr[pos]);
        }
    }
}

int main(){
    int arr[] = {20,40,50,30,10};
    int n = 5;
    CycleSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
