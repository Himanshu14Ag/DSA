
#include<iostream>
using namespace std;

//Naive ----------------
int SqRoot(int x){
    int i = 1;
    while(i*i<=x)
         i++;

    return (i-1);
}

//Optimal Solution ------------
int SqrRoot(int x){
    int low = 1,high = x,ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int sq = mid*mid;

        if(sq == x)
            return mid;
        
        if(sq>x)
            high = mid-1;
        
        else{
            low = mid+1;
            ans = mid;
        }
    } 
    return ans;
}



int main(){
    int x = 10;
    cout<<"Square Root : "<<SqRoot(x)<<endl;
    cout<<"Squared Root : "<<SqrRoot(x)<<endl;
}