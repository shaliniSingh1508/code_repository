class Solution {
public:
    void comb(int index,string &s,string &ans,vector<string> &digits,vector<string> &res){
        if(index==s.size())
        {
            res.push_back(ans);
            return;
        }
        for(char i : digits[s[index]-'0']){
            ans.push_back(i);
            comb(index+1,s,ans,digits,res);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        if(s.size()==0)
            return {};
        vector<string> digits = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ans="";
        vector<string> res;
        comb(0,s,ans,digits,res);
        return res;

    }
};