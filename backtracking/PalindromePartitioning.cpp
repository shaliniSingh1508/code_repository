class Solution {
public:
    void f(int ind,string s,vector<vector<string>> &res,vector<string> &path){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,res,path);
                path.pop_back();
            }

        }
    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        f(0,s,res,path);
        return res;

    }
};