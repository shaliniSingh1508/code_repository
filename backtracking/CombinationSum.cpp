class Solution {
public:
    void combSum(int index,vector<int>&nums, int target,vector<vector<int>> &res,vector<int> &curr){
        if(index == nums.size()) {
            if(target==0){
            res.push_back(curr);
        }
        return;
    }

        if(nums[index] <= target) {
            curr.push_back(nums[index]);
            combSum(index,nums,target-nums[index],res,curr);
            curr.pop_back();
        }
        combSum(index+1,nums,target,res,curr);
    }
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
       vector<vector<int>> res;
        vector<int> curr;

        combSum(0,nums,target,res,curr);
        return res;

    }
};