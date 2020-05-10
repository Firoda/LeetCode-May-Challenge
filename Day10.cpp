class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1 and trust.size() == 0)    return 1;
        if(trust.size() == 0)   return -1;
        unordered_set<int> whoTrust;
        unordered_map<int, int> trust_cnt;
        
        for(int i=0;i<trust.size(); i++)
        {
            whoTrust.insert(trust[i][0]);
            trust_cnt[trust[i][1]]++;
        }
        
        vector<int> cand;
        for(auto it=trust_cnt.begin();it!=trust_cnt.end(); it++)
        {
            if(it->second == N-1 and whoTrust.find(it->first) == whoTrust.end())
            {
                cand.push_back(it->first);
            }
        }
        if(cand.size() == 0 or cand.size() > 1)
            return -1;
        else
            return cand[0];
        
    }
};
