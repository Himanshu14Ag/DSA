
#include <bits/stdc++.h>
using namespace std;
 
void subsets(string st , string curr="",int i=0){ 

    if(i==st.length()){
        cout<<curr<<endl;
        return;
    }

    subsets(st,curr,i+1);
    subsets(st,st[i]+curr,i+1);
}

int main(){
    string st = "ABC";  
    subsets(st);  
}