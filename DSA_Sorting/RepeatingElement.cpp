#include<iostream>
using namespace std;

//boolean Approach -------------------
int repeat(int arr[],int n){
    bool visit[] = {false,false,false,false,false};

    for(int i=0;i<n;i++){
        if(visit[arr[i]])
            return arr[i];
        
        visit[arr[i]] = true;
    }
}

//Efficient Approach ----------------------
int repeatElement(int arr[], int n){
    int slow = arr[0]+1;
    int fast = arr[0]+1;
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast+1]]+1;
    }while(slow!=fast);

    slow = arr[0]+1;

    while(slow!=fast){
        fast = arr[fast]+1;
        slow = arr[slow]+1;
    }
    return slow-1;
}

int main(){
    int arr[] = {0,2,1,3,1,1};
    int n = 6;
    cout<<"Repeat bool : "<<repeat(arr,n)<<endl;
    cout<<"Repeating Element  : "<<repeatElement(arr,n);
}