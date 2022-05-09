class Solution {
public:
    void sub(int index,vector<int>& nums,vector<int> &res,vector<vector<int>> &ans){
        ans.push_back(res);
        for(int i=index; i<nums.size(); i++){
            if(i>index and nums[i]==nums[i-1])
                continue;
            res.push_back(nums[i]);
            sub(i+1,nums,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        sub(0,nums,res,ans);
        return ans;

    }
};