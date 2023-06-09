#include<iostream>
using namespace std;

//Naive solution --------------------
int MaxConstecutiveOnes(bool arr[] , int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr = 0;
        for(int j=i;j<n;j++){
            if(arr[j]==1)
                curr++;
            else
                break;
        }
        res = max(res,curr);
    }
    return res;
}

//Efficient Solution
int MaxCons(bool arr[] , int n){
    int res=0,curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            curr = 0;
        else{
            curr++;
            res = max(curr,res);
        }
    }
    return res;
}


int main()
{
    bool arr[] = {1,1,0,1,0,1,1,1,0,0};
    cout<<"Ans = "<<MaxConstecutiveOnes(arr,10)<<endl;
    cout<<"Ans = "<<MaxCons(arr,10);
}
