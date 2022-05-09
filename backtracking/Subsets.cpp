class Solution {
public:
    void sub(int index,vector<int>& nums,vector<int> &res,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(res);
            return;
        }
        //pick
        res.push_back(nums[index]);
        sub(index+1,nums,res,ans);

        //backtrack
        res.pop_back();

        //not pick
        sub(index+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sub(0,nums,res,ans);
        return ans;
    }
};