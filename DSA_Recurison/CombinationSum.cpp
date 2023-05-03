//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:

    void findCombination(int ind,int target,vector<vector<int>> &ans,vector<int> &arr,vector<int> &ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind],ans,arr,ds);
            ds.pop_back();
        }
        findCombination(ind+1,target,ans,arr,ds);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0,target,ans,candidates,ds);
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<endl;
}	
// } Driver Code Ends


//Input -

// 4
// 7 2 6 5
// 16