class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini=INT_MAX,maxi=INT_MIN;

        for (int i=1; i<n; i++) {
            if(nums[i] < nums[i-1])
                mini = min(mini, nums[i]);
        }
        for (int i=n-2; i>=0; i--) {
            if(nums[i] > nums[i+1])
                maxi = max(maxi, nums[i]);
        }
        if(mini == INT_MAX and maxi == INT_MIN)
            return 0;

        int start=0,end=n-1;

        for (; start<n; start++) {
            if(nums[start] > mini)
                break;
        }
        for(; end>=0; end--) {
            if(nums[end] < maxi)
                break;
        }
        return end-start+1;

    }
};