#include<iostream>
#include<algorithm>
using namespace std;

//Naive -----------------------
void Union(int a[],int b[],int m,int n){
    int c[m+n];
    for(int i=0;i<m;i++)
        c[i] = a[i];
    for(int i=0;i<n;i++)
        c[m+i] = b[i];
    
    sort(c,c+(m+n));

    for(int i=0;i<m+n;i++){
        if(i==0 || c[i]!=c[i-1])
            cout<<c[i]<<" ";
    }
}

//Efficient -----------------------
void Unions(int a[],int b[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(i>0 && a[i]==a[i-1]){
            i++;
            continue;
        }
        if(j>0 && b[j]==b[j-1]){
            j++;
            continue;
        }

        if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }

    while(i<m){
        if(i>0 && a[i]!=a[i-1]){
            cout<<a[i]<<" ";
            i++;
        }
    }
    while(j<n){
        if(j>0 && b[j]!=b[j-1]){
            cout<<b[j]<<" ";
            j++;
        }
    }
}


int main(){
    int a[] = {2,10,20,20};
    int b[] = {2,20,40};
    int m =4, n=3;
    Union(a,b,m,n);
    cout<<endl;
    Unions(a,b,m,n);
}