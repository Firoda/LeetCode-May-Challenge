class Solution {
public:
    string frequencySort(string s) {
        if(s.length() == 0) return "";
        
        unordered_map<char, int> umap;
        
        for(int i=0;i<s.length(); i++)
            umap[s[i]]++;
        
        vector<string> bucket(s.length()+1, "");
        
        for(auto& it: umap)
        {
            int n = it.second;
            char c =  it.first;
            bucket[n].append(n, c);
        }
        
       // sort(counts.begin(), counts.end());
        string res = "";
    
        for(int i=bucket.size()-1; i>=0; i--)
        {
            if(bucket[i].length() > 0)
            {
                res.append(bucket[i]);
            }
        }
        return res;
    }
};
