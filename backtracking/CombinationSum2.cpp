class Solution {
public:
    void comb(int start, int target, vector<int> &a, vector<int> &num, vector<vector<int> > &res) {
        if (target==0) {
            res.push_back(a);
            return;
        }

        for (int i=start; i<num.size(); i++) {
            if (i>start && num[i]==num[i-1])
                continue;
            if(num[i] > target)
                break;
            a.push_back(num[i]);
            comb(i+1, target-num[i], a, num, res);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int> > res;
        vector<int> a;
        sort(num.begin(), num.end());
        comb(0, target, a, num, res);
        return res;
    }
};