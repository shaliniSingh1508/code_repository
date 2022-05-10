class Solution {
public: int targetsum(int index,vector<int>& nums,int target){
        if(index==nums.size()){
            if(target==0)
                return 1;
            else
                return 0;
        }
        int pos=targetsum(index+1,nums,target-nums[index]);
        int neg=targetsum(index+1,nums,target+nums[index]);

        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetsum(0,nums,target);

    }
};