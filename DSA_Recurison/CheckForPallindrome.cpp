#include<iostream>
#include<string.h>
using namespace std;

bool isPallindrome(string str , int start , int end){

    if(start >= end)
        return true;

    return (str[start]==str[end]) && isPallindrome(str,start+1,end-1);
    
}

int main(){
    
    string str = "aabbccbbaa";
    int n = str.length();
    int start = 0 , end = n-1;

    cout<<isPallindrome(str , start , end); 

}