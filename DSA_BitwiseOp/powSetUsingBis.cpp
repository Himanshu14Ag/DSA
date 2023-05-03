#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;


void powSet(string str){

    int n = str.length();
    int powSize = pow(2,n);

    for(int count = 0 ; count < powSize ; count++){
        for(int j=0 ; j<n ; j++){
            if((count & (1<<j)) != 0)
                cout<<str[j];
        }
        cout<<endl;
    }

}

int main(){
    string st = "abc";
    powSet(st); 
}