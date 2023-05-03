#include<iostream>
using namespace std;

//Quick sort with Lomuto Partition ---------------------
int LomutoPartition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void Quick(int arr[],int low,int high){
    if(low<high){
        int p = LomutoPartition(arr,low,high);
        Quick(arr,low,p-1);
        Quick(arr,p+1,high);
    }
}

//Quick Sort with Hoare Partition -----------------------
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
            return j;
        }
        swap(arr[i],arr[j]);
    }
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int p = HoarePartition(arr,low,high);
        QuickSort(arr,low,p);
        QuickSort(arr,p+1,high);
    }
}

//Main Function --------------------------------

int main(){
    int arr[] = {8,4,7,9,3,10,5};
    int low = 0, high = 6;
    
    QuickSort(arr,low,high);
    for(int i=0;i<=high;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    Quick(arr,low,high);
    for(int i=0;i<=high;i++)
        cout<<arr[i]<<" ";

}
