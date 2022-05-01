class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> mpp;
        int res=INT_MAX;

        for (int i=0; i<cards.size(); i++) {
            if(mpp.count(cards[i])) {
                res = min(res, i-mpp[cards[i]]+1);
            }
            mpp[cards[i]]=i;
        }
        return res==INT_MAX ? -1 : res;

    }
};