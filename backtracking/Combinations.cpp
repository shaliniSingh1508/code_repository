class Solution {
public:
    void helper(int index,int n,int k,vector<int> &nums,vector<vector<int>> &res){
        if(nums.size()==k){
            res.push_back(nums);
            return;
        }
        if(index>n)
            return;
        nums.push_back(index);
        helper(index+1,n,k,nums,res);
        nums.pop_back();
        helper(index+1,n,k,nums,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums;

        helper(1,n,k,nums,res);
        return res;
          }
};