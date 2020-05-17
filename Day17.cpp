class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.length() > s.length()) return {};
        if(s.length() == 0 and p.length() != 0) return {};
        
        vector<int> res;
        int countP[26];
        memset(countP, 0, sizeof(countP));
        int countS[26];
        memset(countS, 0, sizeof(countS));
        
        for(int i=0;i<p.length(); i++)
            countP[p[i] - 'a']++;
        
        
        for(int i=0;i<p.length(); i++)
            countS[s[i] - 'a']++;
        
        if(isEqual(countS, countP))
            res.push_back(0);
        
        int start = 0;
        for(int i=p.length(); i<s.length(); i++)
        {
            countS[s[i] - 'a']++;
            countS[s[start]-'a']--;
            if(isEqual(countS, countP))
                res.push_back(start+1);
            start++;
        }
        
        return res;
        
    }
    
    bool isEqual(int countS[26], int countP[26])
    {
        for(int i=0;i<26;i++)
        {
            if(countS[i]!=countP[i])
                return false;
        }
        return true;
    }
};
