#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    
    for(auto x : s)
        cout<< x <<" ";

    cout<<endl;

    s.erase(15);
    
    for(auto x : s)
        cout<< x <<" ";
    
    return 0;
}