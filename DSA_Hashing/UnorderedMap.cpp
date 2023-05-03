#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> m;
    m["gfg"] = 20;
    m["ide"] = 10;
    m.insert({"course",15});

    for(auto x : m)
        cout<<x.first<<" "<<x.second<<endl;
    
    return 0;
}