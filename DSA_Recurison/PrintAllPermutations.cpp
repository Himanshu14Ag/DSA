
#include<bits/stdc++.h>
using namespace std;


void permute(int ind,vector<int> &nums,vector<vector<int>> &arr){
    if(ind == nums.size()){
        arr.push_back(nums);
        return;
    }       

    for(int i=ind;i<nums.size();i++){
        swap(nums[i],nums[ind]);
        permute(ind+1,nums,arr);
        swap(nums[i],nums[ind]);
    }
}

vector<vector<int>> permuteSol(vector<int>& nums){
    vector<vector<int>> ans;
    permute(0,nums,ans);
    return ans;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permuteSol(nums);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}