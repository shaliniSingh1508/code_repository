class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;

        for (int i=0; i<s.size(); i++) {
            if(st.empty() or st.top().first!=s[i])
                st.push({s[i],1});
            else{
                int cnt = st.top().second;
                st.pop();
                st.push({s[i],cnt+1});
            }
            if(st.top().second == k)
                st.pop();
        }

        string res="";
        while(!st.empty()) {
            char ch = st.top().first;
            int times = st.top().second;
            st.pop();
            string u="";
            for (int i=1; i<=times; i++)
                u=u+ch;
            res = u+res;
        }
        return res;

    }
};