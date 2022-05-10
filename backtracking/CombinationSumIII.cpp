class Solution {
public:
    void comb(vector<vector<int>> &res,vector<int> &ans,int index,int k,int n){
        if(ans.size()==k and n==0){
            res.push_back(ans);
            return;
        }
        if(index>n || index>9)
            return;
        //pick
        ans.push_back(index);
        comb(res,ans,index+1,k,n-index);

        //backtrack
        ans.pop_back();

        //not pick
        comb(res,ans,index+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;

        comb(res,ans,1,k,n);
        return res;

    }
};