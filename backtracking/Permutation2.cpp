class Solution {
public:
    void permute(int index,vector<int>& nums,vector<vector<int>> &res){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            if(i>index and nums[i]==nums[index])
                continue;
            swap(nums[i],nums[index]);
            permute(index+1,nums,res);
        }
        for(int i=nums.size()-1; i>index; i--){
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        permute(0,nums,res);
        return res;
    }
};