#include<iostream>
using namespace std;

// Naive Solution

int maxProfit(int price[],int start,int end){
    if(end<=start)
        return 0;
    
    int profit = 0;

    for(int i=start; i<end; i++){
        for(int j=i+1; j<=end; j++){
            if(price[j]>price[i]){
                int currProfit = price[j] - price[i] + maxProfit(price,start,i-1)+maxProfit(price,j+1,end);

                profit = max(profit,currProfit);
            }
        }
    }
    return profit;
}

// Optimal Solution

int maxP(int price[],int n){
    int profit=0;
    for(int i=1;i<n;i++){
        if(price[i]>price[i-1])
            profit += price[i] - price[i-1]; 
    }
    return profit;
}

int main(){

    int arr[] = {1,5,3,8,12};
    int start = 0 , end = 4, n = 5;

    cout<<"Max Profit "<<maxProfit(arr,start,end)<<endl;
    cout<<"Max Profit "<<maxP(arr,n);

}