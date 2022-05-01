class Solution {
public:
    long long atMost(vector<int>& a, int k)
    {
        int start=0,end;
        long long res=0;
        vector<int> mpp(26,0);

        for(end=0; end<a.size(); end++)
        {
            if(mpp[a[end]]==0)
            {
                k--;
            }
            mpp[a[end]]++;
            while(k<0 and start<=end)
            {
                mpp[a[start]]--;

                if(mpp[a[start]]==0)
                    k++;

                start++;
            }
            res+=(long long)(end-start+1);
        }
        return res;
    }

    long long subarraysWithKDistinct(vector<int>& a, int k) {
        return atMost(a,k)-atMost(a,k-1);

    }
    long long appealSum(string s) {
        vector<int> a;
        long long ans=0LL;

        for(int i=0; i<s.size(); i++) {
            a.push_back(s[i]-'a');
        }

        for(int i=1; i<=26; i++) {

            long long cnt=subarraysWithKDistinct(a,i);
            ans+=(long long)(i*cnt);
        }
        return ans;

    }
};