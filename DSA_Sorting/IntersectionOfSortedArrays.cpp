
#include<iostream>
using namespace std;

//Naive --------------------
void Intersection(int a[],int b[],int m,int n){
    for(int i=0;i<m;i++){
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
        }
    }
}

//Efficient ---------------
void Intersect(int a[],int b[],int m,int n){
    int i=0, j=0;
    while(i<m && j<n){
        if(i>0 && a[i] == a[i-1]){
            i++;
            continue;
        }
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}

int main(){
    int a[] = {10,20,20,40,60};
    int b[] = {2,20,20,20};
    int m = 5, n = 4;
    Intersection(a,b,m,n);
    cout<<endl;
    Intersect(a,b,m,n);
}