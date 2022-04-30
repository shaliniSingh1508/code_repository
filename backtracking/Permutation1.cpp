class Solution {
public:
    void permute1(int index,vector<int>& nums,vector<vector<int>> &res){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i],nums[index]);
            permute1(index+1,nums,res);
            swap(nums[i],nums[index]); // backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute1(0,nums,res);
        return res;

    }
};